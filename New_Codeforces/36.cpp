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

bool check(lo i, lo j, lo n)
{
	if(i < 0 || j < 0 || i >= n || j >= n)return false;
	return true;
}

void dfs(vector<vector<lo>>&visited, vector<string>&mat, lo i, lo j)
{
	visited[i][j] = true;
	
	lo x = i - 1, y = j, n = mat.size();

	if(check(x, y, n) && !visited[x][y] && mat[x][y] == '1')
	{
		dfs(visited, mat, x, y);
	}

	x = i, y = j - 1;

	if(check(x, y, n) && !visited[x][y] && mat[x][y] == '1')
	{
		dfs(visited, mat, x, y);
	}	
}



void solve()
{
	lo n; cin >> n;

	vector<vector<lo>>visited(n+1, vector<lo>(n+1));

	vector<string>mat(n+1);

	REP(0, n)
	{
		cin >> mat[i];
		mat[i].push_back('1');
		mat[n].push_back('1');
	}

	mat[n].push_back('1');


	for(int i = 0; i <= n; i++)
	{
		dfs(visited, mat, i, n);
	}

	for(int i = 0; i <= n; i++)
	{
		dfs(visited, mat, n, i);
	}

	

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(mat[i][j] == '1' && !visited[i][j])
			{
				cout << "NO" << endl;
				return;
			}
		}
	}

	cout << "YES" << endl;

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

	lo T; cin >>T;

	while(T--)
	{
		solve();
	}

	return 0;

}