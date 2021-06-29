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
	lo A,B;
	cin>>A>>B;
	lo rem = 0,count1=0,count2=0;
	while(1){
		
		rem = A%2;
		A = A/2;
		if(rem==1)break;
		else
		count1++;
	}
	rem = 0;
	while(1){
		
		rem = B%2;
		B = B/2;
		if(rem==1)break;
		else count2++;
	}
	if(A!=B){
		cout<<(-1)<<endl;
		return;
	}
	lo X = abs(count1-count2);

	lo n1=0,n2=0,n3=0;
	if(X>=3){
		n1 = X/3;
		X=X%3;
	}

	if(X>=2){
		n2 = X/2;
		X = X%2;
	}
	if(X>=1){
		n3 = X/1;
		X = X%1;
	}
	if(X!=0){cout<<(-1)<<endl;
	return;}

	lo ans = n1+n2+n3;
	cout<<ans<<endl;



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
