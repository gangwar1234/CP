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

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

ll solve(string s, int k){
    ll cnt=0, len=100003;
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(s.length()+1, vector<ll>(k + 10, 0)));
    
    for(int i=0;i<s[0]-'0';i++) dp[0][1][(i)%k] = 1;

    dp[1][1][(s[0]-'0')%k] = 1;
    
    for(int pos=2;pos<=s.length();pos++){
        
        for(int mod = 0; mod < k; mod++)
        {

            for(int digit=0;digit<=9;digit++){
            
          
                dp[0][pos][mod] += dp[0][pos - 1][ (k + (mod - digit)%k)%k];

                if(s[pos - 1] - '0' > digit)
                {   
                    dp[0][pos][mod] += dp[1][pos - 1][(k + (mod - digit)%k)%k];
                }   
                else if(s[pos - 1] - '0' == digit)
                {
                    dp[1][pos][mod] += dp[1][pos - 1][(k +  (mod - digit)%k)%k];
                } 
            }

        }
       
    }
    
    return dp[0][s.length()][0]%MOD;
}

int main(){
    int k;
    string n;
    cin>>n>>k;
    cout<<solve(n, k)<<endl;

    return 0;
}
  
