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
	lo N,X;
	cin>>N>>X;
	vl v(N);
	cin>>v;
	int len1 = N;
	int sum = accumulate(v.begin(),v.end(),0);
	int sum1=sum;
	if(sum%X!=0){cout<<N<<endl;return;}
	for(int i=0;i<N&&v[i]%X==0;i++){
		len1--;sum1-=v[i];
	}

	if(sum1%X!=0){cout<<len1<<endl;return;}
	int len2 =N;
	int sum2 = sum;
	for(int i = N-1;i>=0&&v[i]%X==0;i--){
		len2--;
		sum2-=v[i];
	}
	debug(len2);
	debug(sum2);
		if(sum2%X!=0){cout<<len2<<endl;return;}
		int len= N - (len1+len2);
		sum = (sum)- (sum1+sum2);
		cout<<(len-1)<<endl;return;

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