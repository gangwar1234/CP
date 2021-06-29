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
lo X; cin>>X;
lo ans;
if(X>=400&&X<=599)ans = 8;
else if(X>=600&&X<=799)ans = 7;
else if(X>=800&&X<=999)ans = 6;
else if(X>=1000&&X<=1199)ans = 5;
else if(X>=1200&&X<=1399)ans = 4;
else if(X>=1400&&X<=1599)ans = 3;
else if(X>=1600&&X<=1799)ans = 2;
else if(X>=1800&&X<=1999)ans = 1;
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