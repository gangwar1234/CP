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
	cin>>N;
	vl v(N);
	cin>>v;
	for(int k=1;k<2048;k++){
		bool flag = true;
		unordered_map<lo,lo>m;
		for(int j=0;j<N;j++){
			m[v[j]^k] = 1;
		}
		for(int i=0;i<N;i++){
			if(!m[v[i]]){
				flag = false;
			}
		}

		if(flag){
			cout<<k<<endl;return;
		}
	}
	cout<<(-1)<<endl;
	return;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T;
	cin>>T;
	while(T--){
	solve();
	}
	return 0;
}