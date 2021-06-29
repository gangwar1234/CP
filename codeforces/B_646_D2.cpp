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
		int N = s.length();
		if(N==1){
			cout<<0<<endl;
			return;
		}

		vl left0(N,0),right0(N,0),left1(N,0),right1(N,0);
		REP(1,N){
			if(s[i-1]=='0')
			{
				left0[i] = left0[i-1] + 1;
				left1[i] = left1[i-1];
			}
			else
			{
				left1[i] = left1[i-1] + 1;
				left0[i] = left0[i-1];
			}
			
		}

		for(lo i = N-2;i>=0;i--){
			if(s[i+1]=='0'){
				right0[i] = right0[i+1] + 1;
				right1[i] = right1[i+1];
			}
			else
			{
				right1[i] = right1[i+1] + 1;
				right0[i] = right0[i+1];
			}
			

		}

		lo ans = s.length();
		REP(0,N){
			ans = min(ans,min(left1[i]+right0[i],left0[i]+right1[i]));
			 
		}
		cout<<ans<<endl;

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