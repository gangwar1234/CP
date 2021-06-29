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
		
		lo N, M, res = 0, x;	cin >> N >> M;
	
		unordered_map<lo, lo>cnt;

		REP(0, N)
		{
			cin >> x;

			cnt[x % M]++;
		}

		if(cnt[0])res++;

		REP(1, M/2+1)
		{
			lo a = min(cnt[i], cnt[M - i]), b = max(cnt[M - i], cnt[i]);

			if(a)
			res += 1 + max(0LL, abs(a - b) - 1);
			else res+=b;
		}

		cout << res << endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T; lo i = 1;
	while(T--){
	solve(i);
	i++;
	}
	return 0;
}