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

    lo N,d; cin>>N>>d;
    vl v(N);
    cin>>v;
    lo ans = 0;
    sort(v.begin(),v.end(),greater<lo>());
    REP(0,N){
        if(v[i]>d){
        lo a = v[i] - d;
        ans += (v[i]*(v[i]+1)/2) - (a*(a+1)/2);  
        cout<<ans<<endl;return;
        }
        else
        {   if(d<=0){
            cout<<ans<<endl; return;
        }
            ans += (v[i]*(v[i]+1)/2);
            d-=v[i];
        }
        

    }
    cout<<ans<<endl;	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    lo T;
    cin>>T;
	cout.precision(20);
    while(T--){
	solve();
    }
	return 0;
}