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
		
		lo N; cin >> N;

		vl v(N);  cin >> v;

		vl ans(N);

		sort(all(v));

		lo l = 0, r = N - 1, i = 0;

		while(l <= r)
		{
			ans[i++] = v[r--];
			ans[i++] = v[l++];

		}

		cout << (( N - 1)/2) << endl;

		REP(0,N)
		{
			cout << ans[i] <<" ";
		}



}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout.precision(20);

	lo T = 1;  lo i = 1;
	while(T--){
	solve(i);
	}
	return 0;
}