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
	lo n, m, m1, lang, count = 0; cin >> n >> m;

	vector<vector<lo>>v(n);

	for(int i = 0; i < n; i++)
	{
		cin >> m1;

		for(int j = 0; j < m1; j++)
		{
			cin >> lang;
			v[i].push_back(lang);
		}
	}

	vector<vector<lo>>g(n);

	for(int i = 0; i < n; i++)
	{
		vector<lo>mark(n, 0);

		for(int j = 0; j < v[i].size(); j++)
		{
			for(int k = i + 1; k < n; k++)
			{
				if(mark[k])continue;

				for(int l = 0; l < v[k].size(); l++)
				{
					if(v[i][j] == v[k][l])
					{
						g[i].push_back(k);
						g[k].push_back(i);
						mark[k] = 1;
						break;
					}
				}
			}
		}
	}

	lo cnt = 0;	vector<lo>visited(n,0);

	for(int i = 0; i < n; i++)
	{
		if(visited[i])continue;
		dfs(i, g, visited);
		cnt++;
	}

	for(int i = 0; i < n; i++)
	{
		if(v[i].size() == 0)count++;
	}

	cout << max(count, cnt-1) << endl;
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