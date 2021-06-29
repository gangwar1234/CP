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
		lo N; cin>>N; vl v(2*N);
		cin>>v;
		unordered_map<int,int>m;
		vector<int>ans;
		for(int i=0;i<2*N;i++){
			if(!m[v[i]]){ans.push_back(v[i]);m[v[i]]++;}
		}

		for(auto a : ans)cout<<a<<" ";
		cout<<endl;
		return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T;
	while(T--){
	solve();}
	return 0;

}