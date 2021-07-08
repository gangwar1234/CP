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



void solve(int T)
{
    int n = 1;

  vector<vector<string>>mat{{"1", "2", "3", "4"},
                            {"?", "6", "7", "8"},
                            {"9", "10", "11", "12"},
                            {"13", "14","15","16"},
                            }
                            ;

  vector<pair<string, int>>matP;



        for(int j = 0; j < n; j++)
        {
            int x = 1;

            for(int i = 0; i < 4; i++)
            {
                for(int k = 0; k < 4; k++)
                {
                    if(mat[i][4*j+k] == "?")
                    {
                        mat[i][4*j+k] = to_string(x);

                        matP.push_back({to_string(x), j});
                    }
                    x++;
                }
               
            }

        }

        stable_sort(matP.begin(), matP.end());

        

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; T = 1; lo i = 1;
	solve(T);
	return 0;
}