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

void solve()
{
	int N;
	cin >> N;
	vector<vector<int>>v(N, vector<int>(N));
	// cout << N << endl;

	for(int i = 0; i < N; i++)for(int j = 0; j < N; j++){char a; cin >> a;v[i][j]=a-'0';}


	vector<vector<int>>dp(N+1, vector<int>(N+1)), dp1(N+1, vector<int>(N+1));

	for(int j = 1; j <= N; j++)dp1[1][j]=1;

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + v[i-1][j-1];
		}
	}

// 	for(int i = 1; i <= N; i++){for(int j = 1; j <= N; j++){cout << dp[i][j];}cout <<endl;}

// cout << endl<<endl;
	for(int i = 2; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			int x, y;
			if(dp[i-1][j] > dp[i][j-1])dp1[i][j] = dp1[i-1][j];
			if(dp[i][j-1] > dp[i-1][j])dp1[i][j] = dp1[i][j-1];
			if(dp[i][j-1] == dp[i-1][j])dp1[i][j]=(dp1[i-1][j]+dp1[i][j-1])%MOD;
		}
	}
	// for(int i = 1; i <= N; i++){for(int j = 1; j <= N; j++){cout << dp1[i][j];}cout <<endl;}

	cout << dp[N][N] << " " << dp1[N][N] << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	// freopen("in.txt","r",stdin);
	solve();
	return 0;
}