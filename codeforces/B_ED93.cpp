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


void solve(lo T){
		
        string s; cin>>s;

        vl v; lo count = 0;

        REP(0,s.length()){

            if(s[i]!='1'){

                v.push_back(count);
        
                count = 0;
            }
            else count++;

        }

        v.push_back(count);

         count = 0;

        sort(v.begin(),v.end(),greater<lo>());
        // REP(0,v.size())cout<<v[i]<<" ";
        // cout<<endl;
        REP(0,v.size()){
            if(i%2==0)count+=v[i];

        }
        cout<<count<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
    // freopen("in.txt","r",stdin);
	lo T; cin>>T; lo i = 1;
	while(T--){
	solve(i);
	}
	return 0;
}