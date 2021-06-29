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

bool cycle = false;
lo dir_x[4] = {0,0,1,-1};
lo dir_y[4] = {1,-1,0,0};

bool check(lo i, lo j, lo n, lo m)
{
	if(i < 0 || j < 0 || i >= n || j >= m)return false;

	return true;
}

void dfs(lo x, lo y, vector<string>&mat, vector<vector<lo>>&dp, vector<vector<lo>>&vis, lo par_x, lo par_y, char curr, lo init_x, lo init_y, lo curr_p)
{
	vis[x][y] = 1;	lo n = mat.size(), m = mat[0].size();

	cout << "x : " << x << " y : " << y << " curr_p : " << curr_p << " curr char : " << curr << endl;

	for(int i = 0; i < 4; i++)
	{
		lo xx = dir_x[i] + x;
		lo yy = dir_y[i] + y;

		lo temp = curr_p;

		if(!check(xx, yy, n, m) || (xx == par_x && yy == par_y))continue;

		if(vis[xx][yy] == 2)continue;
		
		if(curr == 'D' && mat[xx][yy] == 'I')
		{

					if(vis[xx][yy] == 1)
					{	
						cout << " x : " << x << " y : "<< y << " xx : " << xx << " yy : " << yy << " found cycle " << endl;
						cycle = true;
						return;
					}			

			dfs(xx, yy, mat, dp, vis, x, y, 'I', init_x, init_y, temp);


		}
		else if(curr == 'I' && mat[xx][yy] == 'M')
		{
					if(vis[xx][yy] == 1)
					{	
						cout << " x : " << x << " y : "<< y << " xx : " << xx << " yy : " << yy << " found cycle " << endl;
						cycle = true;
						return;
					}		
			dfs(xx, yy, mat, dp, vis, x, y, 'M', init_x, init_y, temp);
		}
		else if(curr == 'M' && mat[xx][yy] == 'A')
		{
					if(vis[xx][yy] == 1)
					{	
						cout << " x : " << x << " y : "<< y << " xx : " << xx << " yy : " << yy << " found cycle " << endl;
						cycle = true;
						return;
					}
			dfs(xx, yy, mat, dp, vis, x, y, 'A', init_x, init_y, temp);
		}
		else if(curr == 'A')
		{
			temp++;

			cout << " x: " << x << " y : " << y << " " << curr_p  << " next letter : " << mat[xx][yy]<< endl;

			if(mat[xx][yy] == 'D')
			{
					if(vis[xx][yy] == 1)
					{	
						cout << " x : " << x << " y : "<< y << " xx : " << xx << " yy : " << yy << " found cycle " << endl;
						cycle = true;
						return;
					}
				if(dp[xx][yy] == -1)
					dfs(xx, yy, mat, dp, vis, x, y, 'D', init_x, init_y, temp);
				else 
				dp[init_x][init_y] = max(dp[init_x][init_y], temp + dp[xx][yy]);
			}

				dp[init_x][init_y] = max(dp[init_x][init_y], temp);

		}

		
		
	}

	if(curr == 'A')
	{
		dp[init_x][init_y] = max(dp[init_x][init_y], curr_p+1);
	}

	cout << " getting out from " << x << " " << y << endl << endl;

	vis[x][y] = 0;
}



void solve()
{
	lo n, m, max_len = 0; cin >> n >> m;

	vector<string>mat(n);

	cin >> mat;

	vector<vector<lo>>dp(n, vector<lo>(m,-1)); vector<vector<lo>>vis;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(mat[i][j] == 'D')
			{
				vis=vector<vector<lo>>(n+1, vector<lo>(m+1,0));
				dfs(i, j, mat, dp, vis, -1, -1, 'D', i, j, 0);

				if(cycle)
				{
					// cout << " i : " << i << " j : " << j << endl;
					cout << "Poor Inna!";
					return;
				}

				// cout << " i : " << i << " j : " << j << " dp : " << dp[i][j] << endl;

				max_len = max(max_len, dp[i][j]);
			}
		}
	}

	if(max_len == 0)
	{
		cout << "Poor Dima!"; return;
	}

	cout << max_len << endl;

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