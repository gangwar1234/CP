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
lo count = 0;
lo a,b;
cin>>a>>b;
	while(a>0&&b>0){

		if(a>b+1){
			a-=2*(a-b-1);
			b-=(a-b-1);
			count+=(a-b-1);
		}
		else if(b>a+1)
		{	count+=(b-a-1);
			a-=(b-a-1);
			b-=2*(b-a-1);
		}
		if(a==b){
			count+=a/2;
			cout<<count<<endl;
			return;
		}
		if(a==b+1){
			count+=(a/2);
			count++;
			cout<<count<<endl;
			return;
		}
		if(b==a+1){
			count+=(b/2);
			count++;
			cout<<count<<endl;
			return;
		}	
		debug(count);
	}
	cout<<count<<endl;
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