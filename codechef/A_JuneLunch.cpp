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
		lo S,N;
		cin>>S>>N;
		if(S==1){cout<<1<<endl;return;}
		if(S%2==0){
			if(S<N){cout<<1<<endl;return;}
			lo x = ceil(double(S)/N);
			cout<<x<<endl;return;
		}
		else
		{	S--;
			if(S<N){cout<<2<<endl;return;}
			lo x = ceil(double(S)/N);
			cout<<(x+1)<<endl;return;
			
		}
		
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