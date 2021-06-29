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


void solve(int T){

	lo N,K,Z; cin>>N>>K>>Z;
	vl v(N); cin>>v;
	vl sum(N), couple(N);
	sum[0] = v[0];
	REP(1,N)sum[i] = sum[i-1] + v[i];
	REP(1,N)couple[i] = max(couple[i-1],v[i]+v[i-1]);
	lo ans = v[0];
	REP(1,N){
		K--;
		lo rem = K%2;
		lo x = min(Z,K/2); 
		ans = max(ans,sum[i] + x*couple[i]+rem*v[i]);

	}
	cout<<ans<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T; int i = 1;
	while(T--){
	solve(i);
	 i++;
	}
	return 0;
}