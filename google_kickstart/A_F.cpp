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

		lo N, X;
	
		cin >> N >> X;

		vector<pair<int, int>>v(N);

		REP(0, N)
		{
			lo a;

			cin >> a;

			v[i] = {ceil((double)a/X), i + 1};
		}

		stable_sort(v.begin(), v.end());

		REP(0, N)
		{
			cout << v[i].second << " ";
		}
		cout << endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T;

	freopen("in.txt", "r", stdin);

	cin >> T;

	lo i = 1;

	while(T--)
	{
		cout << "Case #"<<i<<":" << " ";  
		solve();
	}
	return 0;
}