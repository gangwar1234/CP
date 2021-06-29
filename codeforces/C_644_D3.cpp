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

lo N,odd=0,even=0; cin>>N;
vl v(N);
cin>>v;
sort(all(v));
REP(0,N)if(1&v[i])odd++;
even =  N - odd;
even=even%2; odd = odd%2;
if(even==0){
	cout<<"YES"<<endl;
	return;
}
// for the odd compensation
for(int i=0;i<N-1&&odd>0;i++){
	if(v[i]%2!=0&&v[i]+1==v[i+1])odd--;
}
if(odd==0){
	cout<<"YES"<<endl;
	return;
}


for(int i=0;i<N-1&&even>0;i++){
	if(v[i]%2==0&&v[i]+1==v[i+1])even--;
}
if(even==0){
	cout<<"YES"<<endl;
	return;	
}

	cout<<"NO"<<endl;
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