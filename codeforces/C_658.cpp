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


void solve(int T){
	lo N; cin>>N;
	string a,b; cin>>a>>b;
	a+='0';
	b+='0';
	vl t1,t2;
	REP(1,N+1){
		if(a[i]!=a[i-1])t1.push_back(i);
		if(b[i]!=b[i-1])t2.push_back(i);
	}


	cout<<(t1.size()+t2.size())<<" ";
	REP(0,t1.size())cout<<t1[i]<<" "; reverse(t2.begin(),t2.end());
	REP(0,t2.size())cout<<t2[i]<<" ";
	cout<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T; int i = 1;
	while(T--){
	solve(i);
	 i++;
	}
	return 0;
}