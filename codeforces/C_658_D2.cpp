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

lo max_rectangle(vector<lo>&A){
    
    stack<lo>st; lo i = 0, ans = INT_MIN; 
    while(i<A.size()){
        if(st.empty()||A[st.top()]<=A[i])st.push(i++);
        else{
            lo a = st.top();
            st.pop();
			if(st.empty()){
				ans = max(ans,i*A[a]);
			}
			else 
            ans = max(ans, (i - st.top()-1*A[a]));
        }
    }
    
    while(!st.empty()){
        lo a = st.top();
        st.pop();
			if(st.empty()){
				ans = max(ans,i*A[a]);
			}
			else 
            ans = max(ans, (i - st.top()-1)*A[a]);
    }
    
    return ans;
    
}


void solve(){
	lo N; cin>>N;
	vl v(N); cin>>v;
cout<<max_rectangle(v)<<endl;
	// string a,b;
	// cin>>a>>b;
	// a = a + '0';
	// b = b + '0';
	// for(int i = 0;i<a.length();i++)
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