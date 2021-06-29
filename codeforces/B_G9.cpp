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
	lo N,M; cin>>N>>M;
	vll v(N,vl(M,0)),ans(N,vl(M,0));
	REPV(i,0,N){
		REPV(j,0,M){
			cin>>v[i][j];

		}
	}	



for(int i=0;i<N;i++){
	for(int j=0;j<M;j++){
					if((i==0&&j==0&&v[i][j]>2)||(i==N-1&&j==M-1&&v[i][j]>2)
			||(i==N-1&&j==0&&v[i][j]>2)||(i==0&&j==M-1&&v[i][j]>2)){cout<<"NO"<<endl;return;}
			else if((i==0||j==0||i==N-1||j==M-1)&&v[i][j]>3){cout<<"NO"<<endl;return;}
			else if(v[i][j]>4){cout<<"NO"<<endl;return;}
	}
}

	cout<<"YES"<<endl;
	
	REPV(i,0,N){
		REPV(j,0,M){
			if((i==0&&j==0)||(i==N-1&&j==M-1)
			||(i==N-1&&j==0)||(i==0&&j==M-1)){cout<<"2"<<" ";}
			else if((i==0||j==0||i==N-1||j==M-1)){cout<<"3"<<" ";}
			else cout<<"4"<<" ";
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