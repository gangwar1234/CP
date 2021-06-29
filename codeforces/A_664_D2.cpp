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
		lo r,b,g,w;
		cin>>r>>b>>g>>w;
		int odd=0, even=0;
		if(1&r)odd++;
		else even++;
		if(1&b)odd++;
		else even++;
		if(1&g)odd++;
		else even++;
		if(odd==2&&(1&w)&&r>0&&b>0&&g>0)cout<<"YES"<<endl;
		else if(odd==3||even==3)cout<<"YES"<<endl;
		else if(even==2&&(w%2==0))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		// debug(odd);
		// debug(even);
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