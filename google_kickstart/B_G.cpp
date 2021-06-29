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
		
		lo N;
		
		cin >> N;
		
		vl dia_1(N), dia_2(N);

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{	
				lo a;  cin >> a;

				if(i-j>=0)
				{
					dia_1[i-j]+=a;
				}
				else
				{
					dia_2[j-i]+=a;
				}
				
			}

		}

		lo ans = *max_element(dia_1.begin(), dia_1.end());
		ans = max(ans, *max_element(dia_2.begin(), dia_2.end()));

		cout << ans << endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	freopen("in.txt", "r",stdin);
	lo T; cin >> T; lo  i = 1;
	while(T--)
	{
	cout << "Case #"<<i<<": ";
		solve();
		i++;
	}
	return 0;
}