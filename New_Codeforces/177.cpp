#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define MOD 1000000007
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) 
#define REP(a,b) for(lo i =(a) ;i<(b);i++)

template <typename T>

istream &operator>>(istream &in, vector<T> &v)
{
	for (unsigned i = 0; i < v.size(); i++)
		in >> v[i];
	return in;
}

lo gcd(lo a, lo b)
{
	if(a == 0)return b;

	return gcd(b%a, a);
}

lo power(lo x, lo y)
{
	if(y == 0)return 1;
	lo temp = power(x, y/2);
	temp = (temp*temp)%MOD;
	if(1&y)return (x*temp)%MOD;

	return temp;
}

bool dfs(lo x, lo y, vector<vector<vector<lo>>>&g, lo c, vector<vector<lo>>&visited)
{
	visited[x][c] = true;

	if(x == y)return true;

	for(auto child : g[x])
	{
		if(child[1] == c && !visited[child[0]][c])
		{
			if(dfs(child[0], y, g, c, visited)) return true;
		}
	}

	return false;
}



void solve()
{
	lo n, m, x, y, c, q; cin >> n >> m;

	vector<vector<vector<lo>>>g(n+1);

	for(int i = 0; i < m; i++)
	{
		cin >> x >> y >> c;

		g[x].push_back({y, c});
		g[y].push_back({x, c});
	}

	cin >> q;

	while(q--)
	{
		cin >> x >> y;	lo cnt = 0;

		vector<vector<lo>>visited(n+1, vector<lo>(m+1, 0));

		for(int c = 1; c <= m; c++)
		{
			if(dfs(x, y, g, c, visited))cnt++;
		}

		cout << cnt << endl;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);

	lo T; T = 1;

	while(T--)
	{
		solve();
	}

	return 0;

}