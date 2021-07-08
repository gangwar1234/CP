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

void dfs(lo start, vector<vector<lo>>&g, vector<lo>&visited)
{
	visited[start] = true;
	
	for(auto child : g[start])
	{
		if(!visited[child])
		dfs(child,g,visited);
	}
}



void solve()
{
	lo n, m, k, x, y, l; cin >> n >> m >> k;

	vector<vector<vector<lo>>>v(n+1);

	for(int i = 0; i < m; i++)
	{
		cin >> x >> y >> l;
		v[x].push_back({y, l});
		v[y].push_back({x, l});
	}

	vl ak(k); cin >> ak; lo cost = INT_MAX;

	unordered_map<lo,lo>mp;

	for(int i = 0; i < k; i++)mp[ak[i]]++;

	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < v[ak[i]].size(); j++)
		{
			if(mp[v[ak[i]][j][0]] == 0)
			{
				cost = min(cost, v[ak[i]][j][1]);
			}
		}
	}

	if(cost == INT_MAX) cout << -1 << endl;
	else cout << cost << endl;
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