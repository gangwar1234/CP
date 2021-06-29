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
		string s; cin>>s;
		vector<int>v{0,1,2};
		unordered_map<char,int>m;
		m['R'] = 2; m['P'] = 0; m['S'] = 1;
		int ans = 0,t=0;
		for(int j=0;j<v.size();j++){
			int count=0;
		for(int i=0;i<s.length();i++){
			if(j==(m[s[i]]+1)%3)count++;
		}
		if(count>ans){
			ans = count;
			t = j;
		}

		}

		if(t==0)cout<<string(s.length(),'P')<<endl;
		else if(t==1)cout<<string(s.length(),'S')<<endl;
		else cout<<string(s.length(),'R')<<endl;
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