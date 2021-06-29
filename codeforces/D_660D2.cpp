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


void dfs(lo start,lo ancester,vector<vector<lo>>&g, bool flag, vector<lo>&H, vector<lo>&P,vector<lo>&good,vector<lo>&a)
{

	a[start] = P[start];
	lo sum_good = 0;
	for(auto child : g[start]){
		if(child!=ancester){
			dfs(child,start,g,flag,H,P,good,a);
			a[start]+=a[child];
			sum_good+=good[child];
		}
	}	


	if((a[start]+H[start])%2)flag = false;
	good[start] = (a[start]+H[start])/2;
	if(good[start]>a[start]||good[start]<0)flag = false;
	if(sum_good>good[start])flag = false;


}
void solve(int T){

	lo N,M; cin>>N>>M;
	vl P(N); cin>>P; vl H_idx(N); cin>>H_idx;
	vector<vector<lo>>g(N);
	REP(0,N-1){
		lo a, b;
		cin>>a>>b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}
	bool flag = true;
	vector<lo>good(N,0),a(N,0);
	dfs(0,-1,g, flag,H_idx, P,good,a);
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	freopen("in.txt","r",stdin);
	lo T; cin>>T; int i = 1;
	while(T--){
	solve(i);
	 i++;
	}
	return 0;
}