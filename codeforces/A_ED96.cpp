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


void solve(lo T){
		
		lo N;

		cin >> N;

		vector<lo>dp(N + 10);

		vector<pair<int, int>>P(N + 10);

		dp[0] = 1;

		for(int i = 3; i <= N; i++)
		{
			if(i - 3 >= 0 && dp[i - 3])
			{
				dp[i] = 1;
				P[i] = {i - 3, 3};
			}
			else if(i - 5 >= 0 && dp[i - 5])
			{
				dp[i] = 1;
				P[i] = {i - 5, 5};	
			}
			else if(i - 7 >= 0 && dp[i - 7])
			{
				dp[i] = 1;
				P[i] = {i - 7, 7};
			}
		}

		if(!dp[N])
		{
			cout << -1 << endl;
			return;
		}

		int th = 0, fv = 0, sv = 0;

		while(N > 0)
		{
			if(P[N].second == 7)sv++;
			else if(P[N].second == 5)fv++;
			else if(P[N].second == 3)th++;
			N = P[N].first;	

		}

		cout << th << " " << fv << " " << sv << endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	// freopen("in.txt", "r", stdin);
	lo T; cin>>T; lo i = 1;
	while(T--){
	solve(i);
	}
	return 0;
}