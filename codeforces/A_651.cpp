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



bool is_prime(lo N){

	for(lo i = 2;i*i<=N;i++){
		if(N%i==0)return false;
	}
	return true;

}


void solve(){

lo N;
cin>>N;
lo X = 0;
if(N==1){cout<<"FastestFinger"<<endl;return;}
if(N==2){cout<<"Ashishgup"<<endl;return;}
lo m = log2(N);
if(pow(2,m)==N){cout<<"FastestFinger"<<endl;return;}
	while(N%2==0){
		N=N/2;
		X++;
	}

	if(X>1){
		cout<<"Ashishgup"<<endl;
	}
	else if(X==1){
		if(is_prime(N)){
			cout<<"FastestFinger"<<endl;
		}
	}else
	cout<<"Ashishgup"<<endl;



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