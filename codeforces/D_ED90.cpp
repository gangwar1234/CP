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
	 lo sum = 0;
	REP(0,N){
		if(!(1&i))
		sum+=v[i];
	}
	vl m(2);
	lo s = 0, curr = 0;
	m[0] = INT_MAX;
	m[1] = 0;
	for(int i=0;i<N;i++){
		if(i&1){
			s+=v[i];
		}
		else
		{
			s-=v[i];
		}
		curr = max(curr,s-m[1&i]);
		m[1&i] = min(s,m[1&i]);
		
	}

	cout<<(sum + curr)<<endl;

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