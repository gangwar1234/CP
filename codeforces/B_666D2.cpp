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

bool f(lo c, lo sum, lo n){

	lo exp = ((pow(c, n - 1)) - 1)/(c - 1);

	debug(c);
	debug(exp);


	return (sum > exp );

}

void solve(lo T){
		lo N;
		cin >> N;
		vl v(N);
		cin >> v;

		lo sum = 0;

		REP(0,N)sum+=v[i];

		lo l = 1, r = sum, ans = 0;
		
		while(l <= r){

			lo m = (l + r) >> 1;


			if(f(m, sum, N)){
				ans = max(ans, m);
				 l = m + 1;
			}
			else{
				r = m - 1;
			}

		}


		lo exp = ((pow(ans, N - 1)) - 1)/(ans - 1);

		cout << (sum - exp) << endl;


}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	freopen("in.txt", "r", stdin);

	solve(1);
	
	return 0;
}