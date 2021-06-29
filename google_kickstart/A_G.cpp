#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
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


void solve(){
	string s;
	cin >> s;

	lo N = s.length(), ans = 0;

	vl dp(N);

	for(int i = N-5; i>= 0; i--)
	{
		string p = s.substr(i,5);
		if(p == "START")dp[i] = dp[i + 1] + 1;
		else dp[i] = dp[i + 1];
	}

	// REP(0,N)debug(dp[i]);

	for(int i = 0; i + 4 < N; i++)
	{
		string p = s.substr(i, 4);
		if(p == "KICK")
		{	
			ans+=(dp[i+4]);
		}
	}
	cout<<ans<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	freopen("in.txt", "r",stdin);
	lo T; cin >> T; lo  i = 1;
	while(T--)
	{
	cout << "Case #"<<i<<":";
		solve();
		i++;
	}
	return 0;
}