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

vector<int> ord;
vector<int> used;
vector<vector<int>> g;
void dfs(int v) {
	used[v] = 1;
	for (auto to : g[v]) {
		if (!used[to]) dfs(to);
	}
	ord.push_back(v);
}



void solve(){
		
		lo N,M; cin>>N>>M;
		g = vector<vector<int>>(N+1);
		vector<pair<int,int>>edges;
		REP(0,M){
			int t,x,y; cin>>t>>x>>y;
			if(t==1)g[x].push_back(y);
			edges.push_back({x,y});
		}

		
		ord.clear();
		used = vector<int>(N+1);
		REP(1,N+1)if(!used[i])dfs(i);
		vector<int>pos(N+1);
		reverse(ord.begin(),ord.end());
		REP(0,N)pos[ord[i]] = i+1;

		REP(1,N+1){
			for(auto j : g[i]){
				if(pos[i]>pos[j]){
					cout<<"NO"<<endl;return;
				}
			}
		}

		cout<<"YES"<<endl;
		

			for(auto x : edges){
				if(pos[x.first]<pos[x.second]){
					cout<<x.first<<" "<<x.second<<endl;
				}
				else
				{
					cout<<x.second<<" "<<x.first<<endl;
				}
				
			}
		return;
		
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