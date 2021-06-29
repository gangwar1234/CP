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
	int ans = 0;
	lo N,M,K;
	cin>>N>>M>>K;
	vector<string>v(N);
	REP(0,N)cin>>v[i];
	for(int bit1=0;bit1<1<<N;bit1++){
		for(int bit2=0;bit2<1<<M;bit2++){

		vector<string>temp = v;
		for(int i=0;i<N;i++){
			if(bit1&(1<<i)){
				temp[i] = string(v[i].size(),'r');
			}
		}
		for(int i=0;i<M;i++){
			if(bit2&(1<<i)){
			for(int j=0;j<N;j++){
				temp[j][i] = 'r';
			}
			}
		}
	int count=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(temp[i][j]=='#')count++;
			}
		}
		ans+=(count==K);		

		}
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