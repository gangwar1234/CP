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


void solve(int T){

	lo N; cin>>N; 
	if(N>30){cout<<"YES"<<endl;
		if(N%2){
			lo X = N - ((2*3) + (2*5) + (2*7));
			cout<<6<<" "<<10<<" "<<14<<" "<<X<<endl;
		}
		else{
			if(N==46)
			{
				lo X = N - (37);
				cout<<6<<" "<<10<<" "<<21<<" "<<X<<endl;
			}
			else
			{
				lo X = N - (31);
				cout<<6<<" "<<10<<" "<<15<<" "<<X<<endl;
			}
			
		}

	}
	else cout<<"NO"<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T; int i = 1;
	while(T--){
	solve(i);
	 i++;
	}
	return 0;
}