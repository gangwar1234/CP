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
	vl d(N+1);
	if(N==1){cout<<"Ayush"<<endl;return;}
	REP(0,N-1){
		lo u,v;
		cin>>u>>v;
		d[u]++;d[v]++;
	}
	if(d[X]<=1)cout<<"Ayush";
	else
	{
		if(N%2==0)cout<<"Ayush";
		else{
			cout<<"Ashish";
		}
	}
	cout<<endl;
		
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