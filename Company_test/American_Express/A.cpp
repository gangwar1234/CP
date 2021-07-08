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


int dir_x[8] = {0, 0, 1, -1, 1,-1, 1, -1};
int dir_y[8] = {1, -1, 0, 0, 1, 1, -1, -1};


bool check(int x, int y, int N)
{
    if(x < 0 || y < 0 || x >= N || y >= N)return false;
    return true;
}

void solve(int T)
{
    lo N; cin >> N;

    vector<vector<int>>mat(N+1, vector<int>(N+1));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> mat[i][j];
        }
    }

    int flag_c = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            bool flag = true;

            for(int k = 0; k < 8; k++)
            {
                int x = i + dir_x[k];
                int y = j + dir_y[k]; 

                if(check(x, y, N))
                {
                    if(mat[x][y] >= mat[i][j])   ////////////////////////////
                    {
                        flag = false; 
                    }
                }
            }

            if(flag)flag_c++;
        }
    }

    cout << flag_c <<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; T = 1; lo i = 1;
    freopen("in.txt", "r", stdin);
	solve(T);
	return 0;
}