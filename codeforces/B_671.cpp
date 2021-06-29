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
		
		lo N;

		cin >> N;

		lo count = 0, i = 1;

		while(N > 0)
		{
			lo A = pow(2, i) - 1;

			lo x = A * (A + 1)/2;

			N-=x;

			i++;

			if(N >= 0)
			count++;
		}

		cout << count << endl;

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