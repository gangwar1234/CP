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

void dfs(lo start, vector<vector<lo>>&g, vector<lo>&visited, lo &min_val, vector<lo>&coin)
{
	visited[start] = true;

	min_val = min(min_val, coin[start]);
	
	for(auto child : g[start])
	{
		if(!visited[child])
		dfs(child, g, visited, min_val, coin);
	}
}



void solve()
{
	lo n, m, x, y, cost = 0; cin >> n >> m; vl coin(n); cin >> coin;

	vector<vector<lo>>v(n);

	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--; y--;
		v[x].push_back(y);
		v[y].push_back(x);
	} 

	vector<lo>visited(n);

	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			lo min_val = INT_MAX; 

			dfs(i, v, visited, min_val, coin);

			cost += min_val;
		}
	}

	cout << cost << endl;
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