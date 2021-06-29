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
		
		vl v(5);
		lo p;
		cin>>v;cin>>p;
		REP(0,5)v[i]*=p;
		lo ans = 0;
		REP(0,5)ans+=v[i];
		lo original = 24*5;
		if(ans<=original)cout<<"No";
		else cout<<"Yes";
		cout<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lo T;
	cin>>T;
	cout.precision(20);
	while(T--){
	solve();
	}
	return 0;
}