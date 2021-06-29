#include<bits/stdc++.h>
using namespace std;
#define lo long long int 

void BFS(vector<vector<lo>>&adj, lo start, vector<lo>&res, vector<lo>&intit, vector<lo>&goal)
{
    queue<vector<lo>>q;

    q.push({start, 0, 0, 0});

    vector<lo>visited(adj.size());

    visited[1] = 1;

    while(q.size())
    {
        lo n = q.size();

        while(n--)
        {
            auto a = q.front(); q.pop();

            // cout << " node : "<< a[0] << endl;

            if(1&a[3])intit[a[0]]+=a[2];
            else intit[a[0]]+=a[1];

            if(intit[a[0]]%2 != goal[a[0]])
            {
                res.push_back(a[0]);
                if(1&a[3])a[2]++;
                else a[1]++;
            }

            for(auto child : adj[a[0]])
            {
                if(!visited[child])
                {
                    visited[child] = 1;
                    q.push({child, a[1],a[2], a[3]+1});
                }
            }
            
        }
    }
}

int main()
{
    lo N;

    cin >> N;

    vector<vector<lo>>adj(N+1);

    vector<lo>goal(N+1), init(N+1), res;

    for(int i = 0; i < N - 1; i++)
    {
        lo x, y;

        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    for(int i = 1; i <= N; i++)cin >> init[i];
    for(int i = 1; i <= N; i++)cin >> goal[i];

    BFS(adj, 1, res, init, goal);

    cout << res.size() << endl;

    for(int i = 0; i < res.size(); i++)cout << res[i] << endl;

    cout << endl;

    return 0;
}