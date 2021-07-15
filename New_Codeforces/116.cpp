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
	lo n, x; cin >> n;

	vl v(n); cin >> v;

	vector<vector<lo>> dp(n+1, vector<lo>(4, INT_MAX));

	dp[0] = {0,0,0,0};

	for(int i = 1; i <= n; i++)
	{
		dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1;
		
		if(v[i-1] == 1 || v[i-1] == 3)dp[i][1] = min(dp[i-1][2],  dp[i-1][0]);
		if(v[i-1] == 2 || v[i-1] == 3)dp[i][2] = min(dp[i-1][1], dp[i-1][0]);

	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
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

	lo T; T = 1;

	while(T--)
	{
		solve();
	}

	return 0;

}