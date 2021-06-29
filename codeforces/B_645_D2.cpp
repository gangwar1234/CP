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

    lo 	N;
    cin>>N;

    vl v(N);
    cin>>v;
    map<lo,lo>m;
    REP(0,N)m[v[i]]++;
    lo f_ans = 1,ans = 1;
    for(auto &a : m){
        if(a.first<=ans+a.second-1)f_ans = ans + a.second;
        ans+=a.second;
    }
    cout<<f_ans<<endl;
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