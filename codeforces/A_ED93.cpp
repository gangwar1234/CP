#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) 
#define REP(a,b) for(lo i =(a) ;i<(b);i++)
#define PII pair<int,int>
#define f first
#define s second
template <typename T>

istream &operator>>(istream &in, vector<T> &v)
{
	for (unsigned i = 0; i < v.size(); i++)
		in >> v[i];
	return in;
}


void solve(){
    lo N; cin>>N;
    vector<PII>v;
    REP(0,N){
        lo a; cin>>a;
        v.push_back({a,i+1});
    }
    sort(all(v));
    lo x = v[0].f, y = v[1].f, z = v[N-1].f;
    if(x+y>z&&y+z>x&&x+z>y)cout<<-1<<endl;
    else cout<<v[0].s<<" "<<v[1].s<<" "<<v[N-1].s<<endl;
		
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
    // freopen("in.txt","r",stdin);
    lo T; cin>>T;
    while(T--){
	solve();
    }
	return 0;
}