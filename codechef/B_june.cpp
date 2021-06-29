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
	lo N,M;
	cin>>N>>M;
	vl A(N);
	cin>>A;
	sort(all(A));
	lo idx1 = lower_bound(A.begin(),A.end(),M) - A.begin();
	lo idx2 = upper_bound(A.begin(),A.end(),M) - A.begin();
	unordered_map<int,int>m;
	for(int i=0;i<A.size();i++)m[A[i]]++;

	for(int i=1;i<M;i++){
		if(!m[i]){cout<<-1<<endl;return;}
	}
	lo val = N -  (idx2 - idx1);
	cout<<val<<endl;

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