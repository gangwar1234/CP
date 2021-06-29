#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) 
#define REP(a,b) for(lo i =(a) ;i<(b);i++)
#define MOD 1000000007
template <typename T>

istream &operator>>(istream &in, vector<T> &v)
{
	for (unsigned i = 0; i < v.size(); i++)
		in >> v[i];
	return in;
}


void solve(){
		
		lo N, K, M;

		cin >> N >> K;

		string s;

		cin >> s;	vector<vector<lo>>dp(N+1,vector<lo>(2,1));

		M = ceil((double)N/2);

		dp[1][0] = (s[0]-'a');
		dp[1][1] = 1;

		for(int i = 2; i <= M; i++)
		{
			dp[i][0] = (dp[i-1][0]*(K) + dp[i-1][1]*(s[i-1]-'a'))%MOD;
			dp[i][1] = (dp[i-1][1])%MOD;
		}

		lo res = (dp[M][0] + dp[M][1])%MOD;

		// debug(dp[M][0]);
		// debug(dp[M][1]);

		string a = s.substr(0, N/2);
		string a_rev = a;
		reverse(a_rev.begin(), a_rev.end());

		if(N%2)
		{
			a=a+s[N/2]+a_rev;

			if(a >= s)
			{
				res = (MOD + (res - dp[M][1])%MOD)%MOD;
			}
		}
		else
		{
			a = a + a_rev;
			if(a >= s)res = (MOD + (res - dp[M][1])%MOD)%MOD;
		}
		
		cout << res << endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T, i = 1;

	cin >> T;

	while(T--)
	{
		cout << "Case #"<<i<<": ";
		solve();
		i++;
	
	}
	return 0;
}