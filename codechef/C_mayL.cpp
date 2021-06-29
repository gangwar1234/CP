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
	vl A(N),B(N);
	cin>>A;cin>>B;
	lo dis_A = 0, dis_B = 0, ans = 0;
	for(int i=0;i<N;i++){
		if(dis_A==dis_B&&A[i]==B[i]){
			ans+=A[i];
		}
		dis_A += A[i];
		dis_B +=B[i];
	}
	cout<<ans<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T;
	cin>>T;
	while(T--){
	solve();
	}
	return 0;
}