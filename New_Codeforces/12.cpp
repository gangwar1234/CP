#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define MOD 1000000007
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) 
#define REP(a,b) for(lo i =(a) ;i<(b);i++)

template <typename T>

istream &operator>>(istream &in, vector<T> &v)
{
	for (unsigned i = 0; i < v.size(); i++)
		in >> v[i];
	return in;
}

lo gcd(lo a, lo b)
{
	if(a == 0)return b;

	return gcd(b%a, a);
}

lo power(lo x, lo y)
{
	if(y == 0)return 1;
	lo temp = power(x, y/2);
	temp = (temp*temp)%MOD;
	if(1&y)return (x*temp)%MOD;

	return temp;
}

void dfs(lo start, vector<vector<lo>>&g, vector<lo>&visited)
{
	visited[start] = true;
	
	for(auto child : g[start])
	{
		if(!visited[child])
		dfs(child,g,visited);
	}
}



void solve()
{
	lo n, res= 0; cin >> n; 
	vector<lo>v(n);
	cin >> v;

	if(n == 1 || n == 2)
	{
		cout << n; return;
	}

	vector<vector<lo>>dp(n+1, vector<lo>(n+1,1));

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)if(i!= j)dp[i][j] = 2;
	}

	for(int i = 2; i <= n; i++)
	{
		unordered_map<lo, lo>prevOcur;

		for(int j = 1; j < i; j++)
		{
			lo k = prevOcur[v[i-1]];
			dp[i][j] = max(dp[i][j], dp[j][k]+1);
			prevOcur[v[j-1]] = j;
			res = max(res, dp[i][j]);
		}
	}

	cout << res << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);

	lo T; T=1;

	while(T--)
	{
		solve();
	}

	return 0;

}