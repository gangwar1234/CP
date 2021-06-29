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
	string s;
	cin>>s;
	stack<char>st;

	int i = 0, count = 0;
	while(i<s.length()){
		if(st.empty()||st.top()==s[i]){
			st.push(s[i++]);
		}
		else{
			st.pop();
			i++;
			count++;
		}
	}	
	if(count%2==0){
		cout<<"NET"<<endl;
	}
	else
	{
		cout<<"DA"<<endl;
	}
	
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