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
		vl num(N);
		cin>>num;

		lo count = 2, d = num[1] - num[0], ans = 1;
		REP(2,N){
			if(d != num[i] - num[i-1]){
				ans = max(ans, count);
				count = 2;
				d = num[i] - num[i-1];
			}	
			else{
				count++;
			}
		}

		ans = max(ans, count);

		cout << ans << endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	// freopen("in.txt","r",stdin);
	lo T; cin>>T;
	lo i = 1;
	while(T--){
	cout << "Case #"<<i<<": ";
	solve();
	i++;
	}
	return 0;
}