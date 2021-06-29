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
	string s;  cin >> s; s = ")"+s;
	lo n = s.length();	
	vector<lo>dp(n+1), sp(n+1);

	for(int i = 2; i <= n; i++)
	{
		if(s[i-1] == ')')
		{
			lo x = i - dp[i-1] - 1;

			if(s[x-1] == '(')
			{
				dp[i] = dp[x-1] + dp[i-1] + 2;
				sp[i] = sp[x-1] + sp[i-1];
			}
		}
		else if(s[i-1] == ']')
		{
			lo x = i - dp[i-1] - 1;

			if(s[x-1] == '[')
			{
				dp[i] = dp[x-1] + dp[i-1] + 2;
				sp[i] = sp[x-1] + sp[i-1] + 2;
			}			
		}
 		// cout << " i : " << i << " val : "<< dp[i] << endl;
	}

	lo max_idx, max_val = 0;

	for(int i = 2; i <= n; i++)
	{
		if(max_val <= sp[i])
		{
			max_idx = i;
			max_val = sp[i];
		}

	}

	// cout << max_idx << " " << max_val << endl;

	lo st = max_idx - dp[max_idx];

	string res = s.substr(st, dp[max_idx]);

	cout << max_val/2 << endl << res << endl;
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