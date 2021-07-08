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
	lo m, n; cin >> m >> n;

	vector<vector<lo>>v(m, vector<lo>(n));

	REP(0, m)cin >> v[i];

	vector<lo>row(m,1), col(n,1);

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(v[i][j] == 0)
			{
				row[i] = 0; col[j] = 0;
			}
		}
	}

	vector<vector<lo>>res(m, vector<lo>(n));

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(row[i] && col[j])res[i][j] = 1;
			else res[i][j] = 0;
		}
	}


	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
				lo or_val = 0;

				for(int k = 0; k < n; k++)
				{
					or_val |= res[i][k];
				}

				for(int k = 0; k < m; k++)
				{
					or_val |= res[k][j];
				}
				
				if(or_val != v[i][j])
				{
					cout << "NO" << endl; return;
				}
		}
	}

	cout << "YES" << endl;

	for(int  i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
		{
				cout << res[i][j] << " ";
		}

		cout << endl;
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