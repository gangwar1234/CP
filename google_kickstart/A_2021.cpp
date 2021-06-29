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
		
		string s;
		lo N, K;

		cin >> N >> K;

		cin >> s;

		lo l = 0, r = N - 1, Cnt = 0;

		while(l < r)
		{
			if(s[l] == s[r])Cnt++;
			l++; r--;
		}

		cout << abs(Cnt - K) << endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lo T, i = 1;

	cin >> T;

	cout.precision(20);
	while(T--)
	{
		cout << "Case #"<<i<<": ";
	solve();
	i++;
	}
	return 0;
}