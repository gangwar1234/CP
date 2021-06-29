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
	lo N; cin>>N; string s; cin>>s;
	int A=0,B=0;
	REP(0,N)if(s[i]=='A')A++;else B++;
	if(abs(A-B)==1)cout<<"Y"<<endl;
	else cout<<"N"<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	freopen("alchemy_input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	lo T; cin>>T;
	int i = 1;
	while(T--){
	cout<<"Case #"<<i<<": ";
	solve();
	i++;
	}
	return 0;
}