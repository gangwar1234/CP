#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) 
#define REP(a,b) for(lo i =(a) ;i<(b);i++)
#define f first
#define s second




void solve()
{
	lo A, M, C, max_cost, MAX;

	cin >> A >> M;

	vector<vector<int>>g(A + 1);

	for(int i = 0; i < M; i++)
	{
		int u, v, w;

		cin >> u >> v >> w;

		g[u].push_back({v,w});

	}

	MAX = INT_MAX + 1;

	priority_queue<pair<lo, pair<lo, lo>>>pq;

	pq.push({-0, {1,1}});

	vector<vector<int>>dp(C + 1, vector<int>(A + 1, MAX));

	dp[1][1] = 0;

	while(!pq.empty())
	{
		auto a = pq.top();

		a.pop();

		for(auto child : g[a.s.f])
		{
			auto par = a.s.f;
			auto co = a.s.s;
			if(dp[co][par] + g[par][child] < dp[co + 1][child]  && co + 1 <= C)
			{
				dp[co+1][child] = dp[co][par] + g[par][child];

				pq.push({-dp[co+1][child], {child,co+1}});

			}
		}

	}


	vector<int>res(A + 1, MAX);

	for(int i = 1; i <= A; i++)
	{
		for(int j = 0; j <= C; j++)res[i] = min(res[i], dp[j][i]);
	}

	for(int i = 1; i <= A; i++)
	{
		if(res[i] == MAX)res[i] = -1;
	}



}

int main()
{
	solve();
}