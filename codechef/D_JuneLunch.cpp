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
	lo N,G,A,B;
	cin>>N;
	double x=0,y=0;
	while(N--){
		cin>>G>>A>>B;
		double M = 1 + double(A)/B;
		double K = 1 + double(B)/A;
		double X = double(G)/M;
		double Y = double(G)/K;
		x+=X;
		y+=Y;
	}

	cout << setprecision (6) << fixed << x << " " <<y<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// cout.precision(20);
	lo T;
	cin>>T;
	while(T--){
	solve();
	}
	return 0;
}