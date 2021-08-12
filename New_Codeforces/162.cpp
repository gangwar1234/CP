#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define MAX 100007
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

vector<lo>dp(MAX, 0);

void solve()
{
	lo a, b; cin >> a >> b;

	cout << (MOD + (dp[b] - dp[a-1])%MOD)%MOD << endl;
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

	lo T, K; cin >> T >> K;

	dp[0] = 1;

	for(int i = 1; i < MAX; i++)
	{
		dp[i] = dp[i-1];

		if(i - K >= 0)dp[i] = (dp[i] + dp[i-K])%MOD;
	}

	for(int i = 1; i < MAX; i++)dp[i] = (dp[i-1] + dp[i])%MOD;

	while(T--)
	{
		solve();
	}

	return 0;

}