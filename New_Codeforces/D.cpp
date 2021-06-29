#include<bits/stdc++.h>
using namespace std;
#define lo long long int


void solve()
{
    lo N, cnt = 0;

    cin >> N;

    vector<lo>v(N), v2(N);

    for(int i = 0; i < N; i++)cin >> v[i];

    v2 = v;

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
       if(v[i] != v2[i])cnt++;
    }

    if(cnt <= 2)cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main()
{
    solve();

    return 0;
}