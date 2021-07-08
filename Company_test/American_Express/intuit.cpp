#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) 
#define REP(a,b) for(lo i =(a) ;i<(b);i++)
#define mod 1000000007
template <typename T>

istream &operator>>(istream &in, vector<T> &v)
{
	for (unsigned i = 0; i < v.size(); i++)
		in >> v[i];
	return in;
}


void solve(int T)
{

    lo N;   cin >> N;

    vl coins(N);

    cin >> coins;

    vector<vector<int>>Sum(N+1, vector<int>(N+1)), mul(N+1, vector<int>(N+1, 1));

    for(int x = 1; x <= N; x++)
    {
        for(int y = 1; y <= N; y++)
        {
            for(int k = x; k <= N; k+=y)
            {
                Sum[x][y] = (Sum[x][y] + coins[k-1])%mod;

                mul[x][y] = (coins[k-1] * mul[x][y])%mod;
            }
        }
    }

    lo Q;

    cin >> Q;

    while(Q--)
    {
        lo b, X, Y;

        cin >> b >> X >> Y;

        if(b == 0)
        {
            cout << Sum[X][Y] << endl;
        }
        else
        {
            cout << mul[X][Y] << endl;
        }
        
    }
    

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; T = 1; lo i = 1;
    freopen("in.txt", "r", stdin);
    cin >> T;
    while(T--){
	solve(T);
    }
	return 0;
}