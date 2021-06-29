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


bool cmp(pair<lo,lo>a,pair<lo,lo>b){
	if(a.first==b.first){
		return (a.second<b.second);
	}
	return (a.first>b.first);
}
void solve(){
	lo N,K; cin>>N>>K;
	vl A(N);
	cin>>A;
	vl B(32,0);
	for(int i=0;i<32;i++){
		for(int j=0;j<N;j++){
			if(((1<<i)&A[j]))
			B[i]++;
			
		}
	}

vector<pair<lo,lo>>v(32);
for(int i=0;i<32;i++){
	v[i] = {B[i]*(1<<i),i};

}
sort(v.begin(),v.end(),cmp);
lo x = 0;
for(int i=0;i<32;i++)cout<<v[i].second<<endl;
for(int i=0;i<K;i++)
{
	lo n = v[i].second;
	x+=(1<<n);
}

cout<<x<<endl;

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