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
    lo N, count;

    lo A = 1;   cin >> N;

    count = rec(A, N);

    cout << count << endl;
}

int main()
{
    solve();

    return 0;
}