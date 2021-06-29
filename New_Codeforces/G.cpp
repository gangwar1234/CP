#include<bits/stdc++.h>
using namespace std;
#define lo long long int
#define MAX 10000000
vector<bool>prime(MAX+1,true);
vector<vector<lo>>PrimeFact(MAX+1);
vector<lo>mn(MAX);

void seive()
{
    for(int i = 2; i*i <= MAX; i++)
    {
        if(!prime[i])continue;
        for(int j = i; j <= MAX; j+=i)
        {
            PrimeFact[j].push_back(i);   
            prime[j] = false;
        }
    }
}

void solve()
{

    seive();

    lo N, X;

    cin >> N;

    lo MAX_Xi = 0;

    for(int i = 0; i < N; i++){
        cin >> X;
        MAX_Xi = max(MAX_Xi, X);
        for(auto a : PrimeFact[X])
        {
            mn[a]++;
        }
    }
    
    for(int i = 1; i <= MAX; i++)mn[i] += mn[i-1];



    lo m;   cin >> m;

    while(m--)
    {
        lo l, r;

        cin >> l >> r;


        lo res = mn[min(MAX_Xi, r)] - mn[l-1];

        cout << res << endl;
    }

}

int main()
{
    solve();

    return 0;
}