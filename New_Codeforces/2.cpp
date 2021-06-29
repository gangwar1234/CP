#include<bits/stdc++.h>
using namespace std;
#define lo long long int 

int main()
{
    lo N, l, r, Ql, Qr;

    cin >> N >> l >> r >> Ql >> Qr;

    vector<lo>v(N+1), sum(N+1);

    for(int i = 0; i < N; i++)cin >> v[i];

    for(int i = 1; i <= N; i++)sum[i] = sum[i-1] + v[i-1];

    lo res = INT_MAX;

    for(int i = 1; i <= N; i++)
    {
        lo ext_amount = min((lo)(i-1), N-i+1);
        // cout << " extra amount total : " << ext_amount << endl;
        // cout << " extra at left : " << (i-1 - ext_amount) << endl;
        // cout << "extra at right : " << (N-i+1-ext_amount) << endl;
        res = min(res, sum[i-1]*l + (sum[N] - sum[i-1])*r + max(0LL, (i-1 - ext_amount-1)*Ql) + max(0LL,(N-i-ext_amount)*Qr));
    }

    res = min(res, sum[N]*l + (N-1)*Ql);

    cout << res << endl;

    return 0;
}