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

vl factorize(int X){
	lo s = sqrt(X) + 4;
	vl f(s);
	lo c = 0;
	for(int i = 1; i*i<= X; i++){
		if(X%i != 0)continue;
		f[c++] = i;
		if(i*i != X)f[c++] = X/i;
	}
	return f;
}

void solve(){
	lo N, X;
	cin>>N>>X;
	vl A(N); cin>>A;
	vl f = factorize(X);
	unordered_map<lo,lo>m;
	lo count = 0;
	REP(0,f.size()){
		if(f[i]>N||f[i]==0)continue;
		lo sum = X/f[i];

		lo tot_sum = accumulate(A.begin(),A.begin()+f[i]-1,0), idx = 0;
		vl sum_array;
		for(int j=f[i]-1;j<N;j++){
			tot_sum+=A[j];
			if(tot_sum<=sum){
				m[tot_sum]++;
				sum_array.push_back(tot_sum);
				idx++;
			}
			tot_sum-=A[j-f[i]+1];
		}
		for(int j = 0;j<idx;j++)count+=m[sum-sum_array[j]];
		m.clear();
	}

	cout<<count<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T;
	while(T--){
	solve();
	}
	return 0;
}