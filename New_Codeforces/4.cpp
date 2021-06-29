#include<bits/stdc++.h>
using namespace std;
#define lo long long int
#define MOD 1000000007 

lo power(lo x, lo y)
{
    if(y == 0)return 1;

    lo temp = power(x, y/2);

    if(1&y)return (x*(temp*temp)%MOD)%MOD;

    return (temp*temp)%MOD;
}

void solve()
{
    lo A, B, N;

    cin >> A >> B >> N;

    lo prefix = 1;

    for(int i = 1; i <= N; i++)prefix = (prefix*i) % MOD;

    for(int a_count = 1; a_count <= N; a_count++)
    {
        if(Execellence(a_count))
        {
            res += (power(a_count, MOD-2)*power(N-a_count, MOD-2)) % MOD;
        }
    }

    res = (res * prefix) % MOD;

    cout << res << endl;
}

int main()
{
    solve();
    
    return 0;
}