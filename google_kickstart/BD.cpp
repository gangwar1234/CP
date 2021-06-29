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
	lo 	N; cin>>N; vl v(N);cin>>v;
	vll dp(N+1,vl(4,N));
	for(int i=0;i<4;i++)dp[1][i] = 0;
	for(int i=2;i<=N;i++){
		for(int x = 0;x<4;x++){
			for(int y = 0;y<4;y++){
				int val;
				if(v[i-1]>v[i-2]){
					val = (x<=y);		
				}
				else if(v[i-1]==v[i-2]){
					val = (x!=y);
				}
				else val = (x>=y);
				dp[i][x] = min(dp[i][x],dp[i-1][y] + val);
			}
		}
	}
	lo ans = *min_element(dp[N].begin(),dp[N].end());
	cout << "Case #" << T << ": " << ans << endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T; lo i = 1;
	while(T--){
	solve(i);
	i++;
	}
	return 0;
}