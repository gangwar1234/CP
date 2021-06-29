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
	lo N,M;
	cin>>N>>M;
	unordered_map<int,int>m;
	REP(0,N){
		lo a;
		cin>>a;
		m[a]++;
	}

bool flag = false;
lo ans;

	REP(0,M){
		lo a;
		cin>>a;
		if(m[a]&&flag==false){
			flag = true;
			ans = a;
		}
	}

	if(flag){
		cout<<"YES"<<endl;
		cout<<1<<" "<<ans<<endl;
	}
	else cout<<"NO"<<endl;

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