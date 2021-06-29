#include<bits/stdc++.h>
using namespace std;
#define lo int

bool cmp(vector<lo>&a, vector<lo>&b)
{
    if(a[0] == b[0]) return (a[1] < b[1]);

    return (a[0] < b[0]);
}

void solve()
{
    lo N, cost = 0;

    cin >> N;

    vector<vector<lo>>bomb(N, vector<lo>(2));

    for(int i = 0; i < N; i++)
    {
        cin >> bomb[i][0] >> bomb[i][1];
        cost += 2*((bomb[i][0]!= 0) + (bomb[i][1]!=0) + 1);
    }

    sort(bomb.begin(), bomb.end(), cmp);

    cout << cost << endl;

    for(int i = 0; i < N; i++)
    {
        // cout << " bomb : " << bomb[i][0] << " " << bomb[i][1] << endl;

        if(bomb[i][0])
        {
            cout << "1 " << abs(bomb[i][0]) << " ";
            if(bomb[i][0] > 0)cout << "R" << endl; 
            else cout << "L" << endl;
        }

        if(bomb[i][1])
        {
            cout << "1 " << abs(bomb[i][1]) << " ";
            if(bomb[i][1] > 0)cout << "U" << endl;
            else cout << "D" << endl;
        }

        cout << "2" << endl;

        if(bomb[i][0])
        {
            cout << "1 " << abs(bomb[i][0]) << " ";
            if(bomb[i][0] > 0)cout << "L" << endl; 
            else cout << "R" << endl;
        }

        if(bomb[i][1])
        {
            cout << "1 " << abs(bomb[i][1]) << " ";
            if(bomb[i][1] > 0)cout << "D" << endl;
            else cout << "U" << endl;
        }

        cout << "3" << endl;
    }
}

int main()
{
    solve();

    return 0;
}