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
	string a, b; cin >> a >> b;

	lo n = a.length(), m = b.length(), l = 0, r = 0, cnt = 1;

	vector<vector<lo>>dp(n+1, vector<lo>(26,-1));

	for(int i = n-1; i >= 0; i--)
	{
		dp[i] = dp[i+1];
		dp[i][a[i]-'a'] = i+1;
	}

	// for(int i = 0; i <= n; i++)
	// {
	// 	cout << " i : " << i << " --- ";

	// 	for(int j = 0; j < 26; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}

	// 	cout << endl;
	// }

	while(l < m)
	{
		if(dp[r][b[l]-'a'] == -1)
		{
			r = 0; cnt++;

			// cout << b[l] << " ";
		}

		r = dp[r][b[l]-'a'];

		if(r == -1){cout << -1 << endl; return;}

		l++;
	}

	cout << cnt << endl;
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