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

void dfs(lo start, vector<vector<lo>>&g, vector<lo>&visited, vector<lo>&res, lo &cnt)
{
	visited[start] = true;

	res[start] = cnt;

	for(auto child : g[start])
	{
		if(!visited[child])
		dfs(child,g,visited, res, cnt);
	}

}



void solve()
{
	lo n, m, x, y, k; cin >> n >> m;

	vector<vector<lo>>g(n+1);

	for(int i = 0; i < m; i++)
	{
		cin >> k;
		
		for(int j = 0; j < k; j++)
		{
			if(j == 0)
			{
				cin >> x;
			}
			else
			{
				cin >> y;
				g[x].push_back(y);
				g[y].push_back(x);
			}
		}
	}

	vector<lo>res(n+1);

	vector<lo>visited(n+1);

	lo cnt = 0;

	for(int i = 1; i <= n; i++)
	{
		if(res[i] == 0)
		{
			cnt++;
			dfs(i, g, visited, res, cnt);

			
		}
	}

	unordered_map<lo, lo>mp;

	for(int i = 1; i <= n; i++)mp[res[i]]++;

	for(int i = 1; i <= n; i++)cout << mp[res[i]] << " ";

	cout << endl;
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

	lo T; T=1;

	while(T--)
	{
		solve();
	}

	return 0;

}