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


void dfs( int Sx,int Sy,vector<vector<bool>>&visited, int N, int M,int j){
	visited[Sx][Sy] = true;
	if(j!=0)
	cout<<Sx<<" "<<Sy<<endl;
	j++;
	for(int i = 1;i<=N;i++){
		if(i<=N&&Sy<=M&&!visited[i][Sy]){
			dfs(i,Sy,visited,N,M,j);
		}
	}

	for(int i = 1;i<=M;i++){
		if(Sx<=N&&i<=M&&!visited[Sx][i]){
			dfs(Sx,i,visited,N,M,j);
		}
	}
}

void solve(){

		lo N,M,Sx,Sy;
		cin>>N>>M;
		vector<vector<bool>>vis(N+1,vector<bool>(M+1,false));
		cin>>Sx>>Sy;
		int i = 0;
		dfs(Sx,Sy,vis,N,M,i);

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	solve();
	return 0;
}