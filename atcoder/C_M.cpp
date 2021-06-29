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
		lo N,K; cin>>N>>K; vl v(N); cin>>v;
		lo x = 1;
		for(int i=0;i<K;i++)x=x*v[i];
		lo l = 0,prev = 0;
		prev = x;
		for(int i = K;i<N;i++){
			x = x/v[l++];
			x=x*v[i];
			if(prev<x){
				
				prev = x;
				cout<<"Yes"<<endl;
				
			}
			else {
				prev = x;
				cout<<"No"<<endl;}
			
		}
		
	
		
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	solve();
	return 0;
}