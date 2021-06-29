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
		
		lo N, cost = 0;

		cin >> N;

		vl v(N);

		cin >> v;

		for(int i = 0; i < N - 1; i++)
		{
			int index = i, min_val = v[i];

			for(int j = i + 1; j < N; j++)
			{
				if(v[j] < min_val)
				{
					min_val = v[j];
					index = j;
				}

			}

			reverse(v.begin()+i, v.begin()+index+1);

			cost += (index-i+1);
		}
		
		cout << cost << endl;
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
	
	}
	return 0;
}