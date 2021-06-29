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
    lo M,N;
    cin>>M>>N;
    if(M<N)swap(M,N);
    if(M==1){
        cout<<M<<endl;return;
    }
    else
    {
        if(M%2==0){
            if(N%2==0){
                cout<<((N/2)*(M))<<endl;
            }
            else
            {
            lo a = (M/2);
            cout<<(a*N)<<endl;
                
            }
            

        }
        else
        {
            if(N%2==0){
                cout<<((N/2)*(M))<<endl;
            }
            else
            {
                cout<<((N/2)*(M)+(M/2)+1)<<endl;
            }
            

        }
        
    }
    
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