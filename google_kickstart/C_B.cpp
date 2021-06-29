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
		
		lo G, count = 0;

		cin >> G;

		for(int k = 1; k <= G; k++)
		{
			lo a = 1, b = 2*k-1, c = 2*G;

			lo A = b*b + 4*a*c;

			lo val = sqrt(A);

			if(val*val != A)continue;

			lo X = (-b+val);

			lo Y = (-b-val);

			if(X%2 == 0|| Y%2 == 0)count++;

		}
		
		cout << count << endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T, i = 1;

	cin >> T;

	while(T--)
	{
		cout << "Case #"<<i<<": ";
		solve();
		i++;
	}
	return 0;
}