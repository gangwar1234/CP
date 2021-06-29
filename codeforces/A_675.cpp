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


void solve(lo T){
		
		lo a, b, c;

		cin >> a >> b >> c;

		lo base, lar, small;

		if(a >= b && b >= c )
		{
			lar = a;

			base = b;

			small = c;
		} 

		if(b >= a && b >= c )
		{
			lar = b;

			base = a;

			small = c;
		} 

		if(c >= a && c >= b )
		{
			lar = c;

			base = a;

			small = b;
		} 


		lo ans = sqrt((lar - small) * (lar - small) + (base) * (base));

		cout << ans << endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T; lo i = 1;
	while(T--){
	solve(i);
	}
	return 0;
}