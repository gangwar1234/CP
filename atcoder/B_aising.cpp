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
		lo N; cin>>N;
		lo n = ceil((double)sqrt(N));
		lo count = 0;
		vl dp(N+1,0);
		for(int i = 1;i<n;i++)
		{
			for(int j = 1;j<n;j++){
				for(int k = 1;k<n;k++){
					lo x = i*i + j*j + k*k + i*j + j*k + k*i;
					if(x<=N)
					 dp[x]++;
				}
			}
		}
		for(int i = 1;i<=N;i++)cout<<dp[i]<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	solve();
	return 0;
}