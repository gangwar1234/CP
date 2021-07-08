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

int dir_x[4] = {0, 0, 1, -1};

int dir_y[4] = {1, -1, 0, 0};

bool check(int x, int y, int N, int M)
{
    if(x < 0 || y < 0 || x >= N || y >= M)return false;
    return true;
}



void dfs(vector<vector<int>>&g, int x, int y, int T, int &ans, int value, vector<vector<int>>&Final, vector<vector<int>>&temp)
{
    int p = g[x][y];

    g[x][y] = 0;    int N = g.size(), M = g[0].size();

    if(x == N-1 && y == M-1 && T == 0)
    {   
        if(ans < value)
        {
            Final = temp;
        }
        ans = max(ans, value);
    }

    if(T <= 0)return;

    temp.push_back({x, y});

    for(int i = 0; i < 4; i++)
    {
        int xx = x + dir_x[i];
        int yy = y + dir_y[i];

        if(check(xx, yy, N,M) && g[xx][yy]!=0)
        {
            dfs(g, xx, yy, T - 1, ans, value + (p==2), Final, temp);
        }
    }

    g[x][y] = p;

    temp.pop_back();

}

void solve(int T)
{

    vector<vector<int>>g{{1,1,0,1,0}, {0,1,0,0,1}, {0,1,1,0,1}, {0,0,1,0,0}, {0,0,1,1,1}};
    
    int ans = 0, s = 8;

    vector<vector<int>>Final, temp;

    dfs(g, 0, 0, s,  ans,0, Final, temp);

    for(int i = 0; i < Final.size(); i++)
    {
        cout << Final[i][0] << " " << Final[i][1] << endl;
    }


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