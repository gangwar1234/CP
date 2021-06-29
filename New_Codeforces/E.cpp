#include<bits/stdc++.h>
using namespace std;
#define lo long long int

int x_dir[4] = {0,1,-1,0};
int y_dir[4] = {1,0,0,-1};

bool check(int i, int j, int N, int M)
{
    if(i < 0 || j < 0 || i >= N || j >= M)return false;

    return true;
}

void dfs(vector<string>&s, lo x, lo y, lo &K, vector<vector<int>>&visited)
{
    visited[x][y] = 1;  lo N = s.size(), M = s[0].length();

    for(int i = 0; i < 4; i++)
    {
        int x_v = x_dir[i] + x;
        int y_v = y_dir[i] + y;

        if(check(x_v, y_v, N, M) && !visited[x_v][y_v] && s[x_v][y_v] == '.')
        {
            dfs(s, x_v, y_v, K, visited);
        }
    }

    if(K > 0){
    s[x][y] = 'X';
    K--;
    }
}

void solve()
{
    lo N, M, K; 

    cin >> N >> M >> K;

    vector<vector<int>>visited(N, vector<int>(M));

    vector<string>s(N);

    for(int i = 0; i < N; i++)cin >> s[i];

    for(int i = 0; i < N; i++)for(int j = 0; j < M; j++)if(s[i][j] == '.'){dfs(s, i, j, K, visited);break;}

    for(int i = 0; i < N; i++)cout << s[i] << endl;

}

int main()
{
    solve();

    return 0;
}