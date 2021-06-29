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


void dfs(lo start,vector<lo>&visited,vector<lo>graph[]){
	visited[start] = true;
	for(auto child : graph[start]){
		if(!visited[child]){
			dfs(child,visited,graph);
		}
	}
}


void solve(lo T){
		lo N,M;
		cin>>N>>M;
		vector<lo>visited(N+1,false); vector<lo>graph[N+1];
			REP(0,M){
			lo a, b; cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		lo res = N-1, count = 0;
		for(lo i=1;i<=N;i++){
			if(!visited[i]){
				dfs(i,visited,graph);
				count++;
			}
		}
		count--;
		res = res + count;
	cout<<"Case #"<<T<<": "<<res<<endl; 

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T; int i = 1;
	while(T--){
		solve(i);
		i++;
	}
	return 0;
}