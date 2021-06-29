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
		lo X,Y,Z;
		cin>>X>>Y>>Z;
		if(X==Y&&Y==Z){
			cout<<"YES"<<endl;
			cout<<X<<" "<<Y<<" "<<Z<<endl;
		}
		else if(X==Y&&X>Z){
			cout<<"YES\n"<<Z<<" "<<Z<<" "<<X<<endl;
		}
		else if(Y==Z&&Y>X){
			cout<<"YES\n"<<X<<" "<<X<<" "<<Y<<endl;
		}
		else if(X==Z&&X>Y){
			cout<<"YES\n"<<Y<<" "<<Y<<" "<<Z<<endl;
		}
		else cout<<"NO"<<endl;

		return;

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