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
	unordered_map<lo,lo>m;
	lo N; cin>>N; vector<pair<int,int>>v(N); 
	REP(0,N)cin>>v[i].first>>v[i].second;
	sort(v.begin(),v.end());
	REP(0,N){

		lo a = v[i].first; lo b = v[i].second; lo x,y;
		if(m[a-b])x = max(m[a-b]+b,m[a]);
		else x = max(b,m[a]);
		if(m[a])y = max(m[a]+b,m[a+b]);
		else y = max(m[a+b],b);
		m[a] = x;
		m[a+b] = y;
	}

	lo ans = INT_MIN;

	for(auto a: m){
		ans = max(ans,(lo)a.second);
	}
	cout<<ans<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	lo T; cin>>T; int i = 1;
	while(T--){
		cout<<"Case #"<<i<<": ";
		solve();
		i++;
	}
	return 0;
}