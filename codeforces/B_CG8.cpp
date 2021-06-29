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
	lo value = 2;
	lo ans = 1;
	lo n;
	lo flag = 0, i;
	cin>>n;
	if(n==1){cout<<"codeforces"<<endl;return;}
	while(1){
		ans = 1;
		for( i = 0;i<10;i++){
			ans*=value;
			if(ans>=n){
				flag = 1;
				break;
			}
		}
		
		if(flag ==1)break;
		value++;
	}	
	string s = "";
	string p = "codeforces";
	lo j = 0;
	while(i-->=0){
		s+=string(value,p[j++]);
	}

	for(;j<p.length();j++)s+=p[j];
	cout<<s<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	solve();
	return 0;
}