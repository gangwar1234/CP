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

int x_dir[4] = {0,0,1,-1};
int y_dir[4] = {1,-1,0,0};

bool check(int i, int j, int n, int m)
{
	if(i < 1 || j < 1 || i > n || j > m )return false;
	return true;
}

void solve()
{
	int n, m, k, x=0, y=0; cin >> n >> m >> k;
	vector<vector<int>>vis(n+1,vector<int>(m+1,0));
	queue<vector<int>>q;

	REP(0, k)
	{
		cin >> x >> y;
		q.push({x, y});
		vis[x][y] = 1;
	}

	while(q.size())
	{
		int p = q.size();

		while(p--)
		{
			auto a = q.front(); q.pop();

			x = a[0], y = a[1];

			for(int i = 0; i < 4; i++)
			{
				int xx = x_dir[i] + a[0];
				int yy = y_dir[i] + a[1];

				// cout << " xx : " << xx << " yy : " << yy << " check : " << check(xx, yy, n, m) << " n : " << n << " m : " << m << endl;
				if(check(xx, yy, n, m) && !vis[xx][yy])
				{
					// cout << " xx : " << xx << " yy : " << yy << endl;
					vis[xx][yy] = 1;
					q.push({xx,yy});
				}
			}
		}
	}

	cout << x << " " << y << endl;
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