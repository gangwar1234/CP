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


lo compute(lo a, lo b)
{
	lo min_value = min(a, b);
	lo max_value = max(a, b);

	lo res = max(min_value - 1, 0LL);

	if(min_value*2 <= max_value)return res;
	lo val = (max_value/2) - 1;
	res = max(2*val, 0LL);
	return res;
}

lo calculate(vector<lo>&A)
{

	lo res = 0;

	for(int i = 0; i < 2; i++)
	{
		for(int j = 2; j < 4; j++)res+=compute(A[i], A[j]);
	}
	
	return res;

}


void solve(){
		
		lo N, M;

		cin >> N >> M;

		vector<vector<lo>>mat(N, vector<lo>(M));

		REP(0, N)cin >> mat[i];

		vector<vector<vector<lo>>>dp(N, vector<vector<lo>>(M, vector<lo>(4)));


		//horizontal left to right

		for(int i = 0; i < N; i++)
		{
			lo acc_value = 0;

			for(int j = 0; j < M; j++)
			{
				if(mat[i][j] == 0)
					acc_value = 0;
				else 
					acc_value += mat[i][j]; 
				dp[i][j][0] = acc_value;
			}
		}

		//horizontal  right to left

		for(int i = N - 1; i >= 0; i--)
		{
			lo acc_value = 0;

			for(int j = M - 1; j >= 0; j--)
			{
				if(mat[i][j] == 0)
					acc_value = 0;
				else 
					acc_value += mat[i][j]; 
				dp[i][j][1] = acc_value;
			}
		}

		//Vertical downward

		for(int i = 0; i < M; i++)
		{
			lo acc_value = 0;

			for(int j = 0; j < N; j++)
			{
				if(mat[j][i] == 0)
					acc_value = 0;
				else 
					acc_value += mat[j][i]; 
				dp[j][i][2] = acc_value;
			}
		}

		//Vertical  upward

		for(int i = M - 1; i >= 0; i--)
		{
			lo acc_value = 0;

			for(int j = N - 1; j >= 0; j--)
			{
				if(mat[j][i] == 0)
					acc_value = 0;
				else 
					acc_value += mat[j][i]; 
				dp[j][i][3] = acc_value;
			}
		}


		// cout << " ****************** dp computed *****************" << endl;

		// for(int i = 0; i < N; i++)
		// {
		// 	for(int j = 0; j < M; j++)
		// 	{
		// 		for(int k = 0; k < 4; k++)
		// 		{
		// 			cout << dp[i][j][k] << " ";
		// 		}

		// 		cout << endl;
		// 	}
		// }


		lo res = 0;


		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				res += calculate(dp[i][j]);
			}
		}

		cout << res << endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);

	freopen("in.txt", "r", stdin);

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