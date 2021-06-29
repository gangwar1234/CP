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
	lo N,M,X,Y;
	cin>>N>>M>>X>>Y;
	vector<string>v(N);
	lo N_adj = 0, adj = 0;
	REP(0,N)cin>>v[i];
	REPV(i,0,N){
		REPV(j,0,M){
				if(j+1<M&&v[i][j]=='.'&&v[i][j+1]=='.'){adj++;j++;}
				else if(v[i][j]=='.')
				{
					N_adj++;
				}
				
		}
	}
	debug(Y); debug(X); debug(adj);debug(N_adj);
	if(Y<=2*X){
		cout<<((Y*adj) + (X*N_adj))<<endl;
	}	
	else
	{
		cout<<((adj*2 + N_adj)*X)<<endl;
	}
	
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