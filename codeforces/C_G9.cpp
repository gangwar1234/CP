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
	lo 	N; cin>>N;
	vl v(N); cin>>v;
	stack<lo>st;
	lo i=0;
	while(i<N){
		if(st.empty()||st.top()>v[i])st.push(v[i]);
		else{
			lo a = st.top();
			st.pop();
			if(i==N-1){
				st.push(max(a,v[i]));
			}
			else{
				st.push(min(a,v[i]));
			}

		}
		i++;
	}

	while(!st.empty()){
		lo a = st.top();
		st.pop();
		if(st.empty()){cout<<"YES"<<endl;return;}
		else if(st.top()<a){
			lo b = st.top(); st.pop();
			st.push(max(a,b));
		}
		else {cout<<"NO"<<endl;return;}
	}
	cout<<"YES"<<endl;
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