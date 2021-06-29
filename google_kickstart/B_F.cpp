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
		
		lo N, K;

		cin >> N >> K;

		vector<pair<lo, lo>>v(N);

		REP(0, N)
		{
			lo S, E;

			cin >> S >> E;

			v[i] = {S, E};
		}

		sort(v.begin(), v.end());


		lo S = -1, E = -1, count = 0;

		for(int i = 0; i < v.size(); i++)
		{

				lo new_S = max(v[i].first, E);

				if(new_S < v[i].second)
				{
					lo gap = (v[i].second - new_S)/K;

					count+=(gap);

					lo rem = (v[i].second - new_S) % K;

					if(rem !=0)count++;

					S = v[i].second - rem;

					E = S + K;

				}

		}

		cout << count << endl;

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
		i++;
	}
	return 0;
}