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
	lo N; cin>>N; vl v(N); cin>>v;
	lo r = (N+1)/2;
	lo sum = 0,ans=0;
	for(int i=0;i<r;i++)sum+=v[2*i]; ans = sum;
	for(int i=0;i<N-1;i++){
		sum-=v[(2*i)%N];
		sum+=v[2*(r+i)%N];
		ans = max(ans,sum);
	}
	cout<<ans<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	solve();
	return 0;
}