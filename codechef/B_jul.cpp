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
	
	lo N,M,X,Y; cin>>N>>M>>X>>Y;
	lo x1 , x2 , ans = 0;
	x1 = min(Y,X);
	x2 = min(X,(Y-x1));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(i%2==0){
				if(j%2==0)ans+=x1;
				else ans+=x2;
			}
			else{
				if(j%2==0)ans+=x2;
				else ans+=x1;
			}
		}
	}

	cout<<ans<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T;
	while(T--){
	solve();
	}
	return 0;
}