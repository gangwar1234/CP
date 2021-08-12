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

void rec(vector<vector<lo>>&mat, lo i, lo j, lo n, lo val, lo &cnt)
{
	if(cnt == val)return;

	mat[i][j] = val;

	cnt++;

	if(i + 1 < n && mat[i+1][j] == 0)
	{
		rec(mat, i + 1, j, n, val, cnt);
	}

	if(j - 1 >= 0 && mat[i][j-1] == 0)
	{
		rec(mat, i, j-1, n, val, cnt);
	}
}

void solve()
{
	lo n; cin >> n;

	vector<vector<lo>>mat(n, vector<lo>(n));

	map<lo, lo>m;

	for(int i = 0; i < n; i++)
	{
		cin >> mat[i][i];
		m[mat[i][i]] = i;
	}

	for(int i = n-1; i >=0 ; i--)
	{
		lo cnt = 0;

		rec(mat, i, i, n, mat[i][i], cnt);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cout << mat[i][j] << " ";
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