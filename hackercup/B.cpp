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

	lo N; cin>>N; vector<char>C(N); cin>>C;
	stack<char>st;
	for(int i=0;i<2;i++){
		st.push(C[i]);
	}	
	
	for(int i=2;i<N;i++){
		if(st.size()>=2){
			lo A=0,B=0;
			char x = st.top(); st.pop();
			if(x=='A')A++;
			else B++;
			char y = st.top(); st.pop();
			if(y=='A')A++;
			else B++;
			if(C[i]=='A')A++;
			else B++;
			if(A==2&&B==1)st.push('A');
			else if(A==1&&B==2)st.push('B');
			else{
				st.push(y);
				st.push(x);
				st.push(C[i]);
			}

		}
		else st.push(C[i]);
	}
	if(st.size()==1)cout<<"Y"<<endl;
	else cout<<"N"<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	freopen("in.txt","r",stdin);
	freopen("ot.txt","w",stdout);
	lo T; cin>>T; int i=1;
	while(T--){
		cout<<"Case #"<<i<<": ";
	solve();
	i++;
	}
	return 0;
}