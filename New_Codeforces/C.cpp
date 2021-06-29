#include<bits/stdc++.h>
using namespace std;
#define lo long long int

lo rec(lo A, lo N)
{
    if(A > N)return 0;

    return (1 + rec(A*10, N) + rec(A*10 + 1, N));
}

void solve()
{
    lo N, D, K;

    cin >> N >> K >> D;

    if(N > pow(K,D))
    {
        cout << -1 << endl;
        return;
    }

    vector<vector<lo>>ans(N+1, vector<lo>(D));

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < D; j++)ans[i][j] = ans[i-1][j];

        lo rem = 1;

        for(int j = D-1; j >= 0; j--)
        {
            lo r = (rem + ans[i][j])/K;
            ans[i][j] =(rem + ans[i][j])%K;
            rem = r;
        }
    }

    for(int i = 0; i < D; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cout << (ans[j][i] + 1) << " ";
        }

        cout << endl;
    }
}

int main()
{
    solve();

    return 0;
}