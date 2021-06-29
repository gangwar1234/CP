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
		
		lo A, K;

		cin >> A >> K;

		lo x = A - K;
		lo ans;
		if(x<0){
			ans = abs(x);
		}
		else{
			if(A%2 && K%2 || (!(1&A) && !(1&K))) ans = 0;
			else ans = 1;
		}

	cout << ans << endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);

	// freopen("in.txt","r",stdin);

	lo T; cin>>T; lo i = 1;
	while(T--){
	solve(i);
	}
	return 0;
}