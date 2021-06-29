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
	lo N,ans,x,y;
	cin>>N;
	ans = N-1; x = 1; y = N-1;
	if(N%2==0){cout<<(N/2)<<" "<<(N/2)<<endl;return;}	
	for(lo i=1;i*i<=N;i++){
		if(N%i==0){
		lo a  = i;
		lo b = N - i;
		if(a+b==N){
			if(max(a,b)<ans){
				ans = max(a,b);
				x = a;
				y = b;
			}
		}



		

		if(i*i!=N){
			int a = N/i;
			int b = N - a;	
			if(a+b==N){
			if(max(a,b)<ans){
				ans = max(a,b);
				x = a;
				y = b;
			}
		}
		}

	}
	}

	cout<<x<<" "<<y<<endl;
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