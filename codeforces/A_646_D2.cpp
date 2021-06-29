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
	lo N,X;
	cin>>N>>X;
	vl v(N);
	cin>>v;
	lo even = 0,odd =0;
	REP(0,N){
		if(v[i]%2==0)even++;
		else
		odd++;
	}

	if(odd==0){cout<<"No"<<endl;return;}
	if(even==0&&X%2==0){
		cout<<"No"<<endl;return;
	}	
	if(even+odd==X&&odd%2==0){cout<<"No"<<endl;return;}
	cout<<"Yes"<<endl;
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