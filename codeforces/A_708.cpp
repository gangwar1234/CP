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

		cin >> N; 		vl v(N);

		cin >> v;	sort(all(v));

		vl res1, res2;

		REP(0, N)
		{
			if(res1.size())
			{
				if(res1.back()!= v[i])res1.push_back(v[i]);
				else
				{
					res2.push_back(v[i]);
				}
				
			}
			else
			{
				res1.push_back(v[i]);
			}
		}

		for(auto a : res1)cout << a << " ";

		for(auto a : res2)cout << a << " ";

		cout << endl;

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