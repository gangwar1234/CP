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
	lo n, m; cin >> n; 

	string s; cin >> s;

	vector<vector<lo>>dp(n+1, vector<lo>(3, 0));
	vector<lo>p(n+1,-1);

	for(int i = 1; i <= n; i++)
	{
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + !(s[i-1] == 'R');
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + !(s[i-1] == 'B');
		dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + !(s[i-1] == 'G');
	}

	if(dp[n][0] <= dp[n][1] && dp[n][0] <= dp[n][2]) m = 0;
	else if(dp[n][1] <= dp[n][2] && dp[n][1] <= dp[n][0]) m = 1;
	else if(dp[n][2] <= dp[n][1] && dp[n][2] <= dp[n][0]) m = 2;

	lo i = n;

	while(i > 0 )
	{
		p[i] = m;
		i--;
		
		if(m == 0)
		{
			if(dp[i][1] < dp[i][2])m=1;
			else m = 2;
		}	
		else if(m == 1)
		{
			if(dp[i][0] < dp[i][2])m=0;
			else m = 2;			
		}
		else
		{
			if(dp[i][0] < dp[i][1])m=0;
			else m = 1;
		}
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;

	for(int i = 1; i <= n; i++)
	{
		char r;
		if(p[i] == 0)r = 'R';
		else if(p[i] == 1)r = 'B';
		else if(p[i] == 2)r = 'G';

		cout << r;
	}

	cout << endl;

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