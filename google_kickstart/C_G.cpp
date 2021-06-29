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

bool f(vl &a, lo x, lo &ans, lo N)
{
	lo x_less = 0, x_more = 0; 

	for(auto i : a)
	{
		if(i > x){
			lo a = i - x;

			lo b = N - i + x;
			x_more+=min(a,b);
		}
		else {
			lo a = x - i;
			lo b = N + i - x; 
			x_less+=min(a,b);
		}
	}

	ans = min(ans, x_less + x_more);

	return (x_more >= x_less);
}

void solve(){
		
		lo W, ans = INT_MAX, N;

		cin >> W >> N;
		
		vl v(W);
		
		cin >> v;

		sort(all(v));

		lo l = 0, r = W - 1;

		while(l <= r)
		{
			lo m = (l + r) >> 1;

			if(f(v , v[m], ans, N))
			{
				l = m + 1 ;
			}
			else
			{
				r = m  - 1;
			}
			
		}

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