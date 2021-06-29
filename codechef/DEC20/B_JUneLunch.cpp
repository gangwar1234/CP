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
	lo N,a;cin>>N;
	map<lo,lo>m;
	lo max_elemen = INT_MIN;
	REP(0,N){cin>>a;max_elemen  = max(max_elemen,a); m[a]++;}
	vl ans;
	if(m[max_elemen]>1){cout<<"NO"<<endl;return;}
	for(auto a:m){
		if(a.second>2){
			cout<<"NO"<<endl;return;
		}
		ans.push_back(a.first);
		m[a.first]--;
	}
	for (auto iter = m.rbegin(); iter != m.rend(); ++iter) {
        if(iter->second!=0){
			ans.push_back(iter->first);
		}
    }
	cout<<"YES"<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T;
	cin>>T;
	while(T--){
	solve();
	}
	return 0;
}