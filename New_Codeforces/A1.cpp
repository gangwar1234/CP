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


lo dir_x[4] = {0,0,1,-1};
lo dir_y[4] = {1,-1,0,0};

bool check(lo i, lo j, lo n, lo m)
{
	if(i < 0 || j < 0 || i >= n || j >= m)return false;
	return true;
}

void dfs(vector<vector<lo>>&visited, vector<string>&g, lo x, lo y)
{
	visited[x][y] = 1;

	for(int i = 0; i < 4; i++)
	{
		lo a = x + dir_x[i];
		lo b = y + dir_y[i];

		if(check(a, b, g.size(), g[0].size()) && !visited[a][b] && g[a][b] == '#')dfs(visited, g, a, b);
	}
}



void solve()
{
	lo n, m, res = 0;	cin >> n >> m;
	
	vector<string>v(n);

	for(int i = 0; i < n; i++)cin >> v[i];

	for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)if(v[i][j] == '#')res++;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(v[i][j] == '#')
			{
				vector<vector<lo>>visited(n, vector<lo>(m));
				v[i][j] = '.';
				lo cnt = 1;

				for(int k = 0; k < n; k++)
				{
					for(int l = 0; l < m; l++)
					{
						if(v[i][j] == '#' && !visited[k][l])
							{
								dfs(visited, v, k, l);
								cnt++;
							}
					}
				}

				debug(cnt);

				v[i][j] = '#';
				if(cnt > 1){
					cout << 1 << endl;
					return;
				}
			}
		}
	}

	if(res < 3)cout << -1 << endl;
	else cout << 2 << endl;
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