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
		lo T,i=1; cin>>T;
		while(T--){
		lo N,Q; cin>>N>>Q;
		lo S, K,ans=1; 
		lo v;
		cin>>v;

		cin>>S>>K;
		cout<<" N = "<<N<<" Q = "<<Q<<" S = "<<
		if(S==1){
			ans = K;
		}
		if(S==2){
			 ans = (K+1)%2; ans++;
		}
			
					cout<<"Case #"<<i<<": "<<ans;i++;
		}

		
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	solve();
	return 0;
}