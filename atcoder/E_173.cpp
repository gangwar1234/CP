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




#define mod 1000000007
void solve(){
	lo N,K; cin>>N>>K;
	vl v(N); cin>>v;
	if(N<K){cout<<0<<endl;return;}	
	lo ans = 1;	
	if(N==K){REP(0,K)ans = (mod + (ans*v[i])%mod)%mod; cout<<ans<<endl;return;}
	vector<lo>pos,neg;
	REP(0,N){
		if(v[i]>0)pos.push_back(v[i]);
		else neg.push_back(v[i]);
	}
	sort(neg.begin(),neg.end());
	sort(pos.rbegin(),pos.rend());
	if(1&K){
		if(pos.size()==0){
			reverse(neg.begin(),neg.end());
			REP(0,K)ans = (mod + (ans*neg[i])%mod)%mod;
			cout<<ans<<endl;return;
		}
		ans = pos[0];
		pos.erase(pos.begin());
		K--;
	}
	priority_queue<lo>q;
	for(int i=1;i<pos.size();i++){
		q.push(pos[i]*pos[i-1]);
	}

	for(int i=1;i<neg.size();i++)q.push(neg[i]*neg[i-1]);
	for(int i=0;i<K/2;i++){
		ans = (mod + (ans*(q.top()))%mod)%mod;
		q.pop();
	}
	cout<<ans<<endl;	
}





int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	solve();
	return 0;
}