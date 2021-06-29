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

bool ans = false;

void recur(lo A,lo B,lo C,lo K){
	if(ans==true)return;

	if(K==0){
		if(B>A&&C>B)ans = true;
		return;
	}
	recur((A*2),B,C,(K-1));
	recur(A,(B*2),C,(K-1));
	recur(A,B,(C*2),(K-1));


}


void solve(){
		lo A,B,C,K;
		cin>>A>>B>>C>>K;
		recur(A,B,C,K);
		if(ans)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	solve();
	return 0;
}