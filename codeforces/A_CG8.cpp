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

lo ans = 0;

void rec(lo a,lo b,lo c){
	if(a>c||b>c)return;
	if(a>b){
		ans++;
		rec(a,b+a,c);
	}
	else {ans++; rec(a+b,b,c);}
}

void solve(){
	lo a,b,n;
	cin>>a>>b>>n;
	ans = 0;
	rec(a,b,n);	
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