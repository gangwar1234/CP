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

	lo N; cin>>N; vl A(N); cin>>A; lo current_save = 1000;
	for(int i=1;i<N;i++){
		lo x = 0;
		if(A[i]>A[i-1]){
			x = A[i]*(current_save/A[i-1]);
			current_save = current_save%A[i-1];
			}
			
			current_save+=x;
		
		

	}
	cout<<current_save<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	solve();
	return 0;
}