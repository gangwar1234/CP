#include<bits/stdc++.h>
using namespace std;
#define lo long long int
#define MAX 1000

int x_dir[4] = {0,1,-1,0};
int y_dir[4] = {1,0,0,-1};

bool check(int i, int j, int N, int M)
{
    if(i < 0 || j < 0 || i >= N || j >= M)return false;

    return true;
}

void dfs(vector<vector<lo>>&s, lo x, lo y)
{
    s[x][y] = -1;  lo N = s.size(), M = s[0].size();

    // cout << " x : " << x << " y : " << y << endl;


    for(int i = 0; i < 4; i++)
    {
        int x_v = x_dir[i] + x;
        int y_v = y_dir[i] + y;

        while(check(x_v, y_v, N, M) && s[x_v][y_v]!= 1)
        {
            x_v +=  x_dir[i];
            y_v += y_dir[i];
        }
        if(check(x_v, y_v, N, M) && s[x_v][y_v] == 1)dfs(s, x_v, y_v);
    }

}

void solve()
{
    lo N, x, y, cnt = 0; 

    cin >> N;

    vector<vector<lo>>s(MAX+1, vector<lo>(MAX+1));

    for(int i = 0; i < N; i++){cin >> x >> y; s[x][y] = 1;}

    for(int i = 1; i <= 1000; i++)for(int j = 1; j <= 1000; j++)if(s[i][j] == 1){dfs(s, i, j); cnt++;}

    cout << (cnt - 1) << endl;

}

int main()
{
    solve();

    return 0;
}