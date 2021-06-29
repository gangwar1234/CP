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
		lo N; cin>>N; vl v(N); cin>>v;
		vl right(N);
		right[N-1] = N-1;
		int x = INT_MAX;
		for(int i = N-2;i>=0;i--){
			if(x>v[i+1]){
				x = v[i+1];
				right[i] = i+1; 
			}
			else
			{
				right[i] = right[i+1];
			}
			
		}
		lo min_element = 0;
		for(int i=1;i<N;i++){
			if(v[i]>v[min_element]&&v[i]>v[right[i]]){
				cout<<"YES"<<endl;
				cout<<(min_element+1)<<" "<<(i+1)<<" "<<(right[i]+1)<<endl;
				return;
			}
			if(v[min_element]>v[i]){
				min_element = i;
			}
		}
		cout<<"NO"<<endl;

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