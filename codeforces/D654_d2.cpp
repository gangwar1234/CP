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
	lo N,K,X,Y;
	cin>>N>>K;
	vector<vector<lo>>A(N,vector<lo>(N,0));
	X = 0; Y = 0;
	for(int i=0;i<K;i++){
		A[X][Y] = 1;
		X++; Y++;
		if(Y==N)Y=0;
        if(X==N){
            X=0;
            Y++;
            if(Y==N)Y=0;
		}
}

if(K%N==0)cout<<0;
else cout<<2;
cout<<endl;

for(int i=0;i<N;i++){
	for(int j=0;j<N;j++){
		cout<<A[i][j];
	}
	cout<<endl;
}

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