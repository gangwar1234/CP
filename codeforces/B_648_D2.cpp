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
	lo N;
	cin>>N;
	vl v(N),C(N);
	cin>>v;cin>>C;
	if(N==1){cout<<"Yes"<<endl;return;}
	lo one = 0, zero = 0;
	bool flag = false;
	if(C[0]==0)zero++;
	else one++;
	for(int i=1;i<N;i++){
		if(C[i]==0)zero++;
		else one++;
		if(v[i]<v[i-1])flag=true;	
	}
	if(flag==false){
		cout<<"Yes"<<endl;return;
	}
	if(one==0||zero==0)cout<<"No"<<endl;
	else
	{
		cout<<"Yes"<<endl;
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