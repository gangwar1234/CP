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
	lo n, ui; cin >> n;

	vector<vector<lo>>u(n);	vl s(n);

	for(int i = 0; i < n; i++)
	{
		cin >> ui; ui--;
		u[ui].push_back(i);
	}

	cin >> s;	vl ans(n);

	vector<vector<lo>>pre(n, vector<lo>(1));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < u[i].size(); j++)
		{
			if(j == 0)pre[i].push_back(s[u[i][j]]);
			else pre[i].push_back(pre[i][j] + s[u[i][j]]);
		}

	}

	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 1; j < pre[i].size(); j++)cout << pre[i][j] << " ";
	// 	cout << endl;
	// }

	for(int i = 0; i < n; i++)
	{
		for(int k = 1; k <= u[i].size(); k++)
		{
			ans[k-1] += pre[i][(u[i].size()/k)*k]; 
		}
	}

	for(int i = 0; i < n; i++)cout << ans[i] << " ";
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

	lo T; cin >>T;

	while(T--)
	{
		solve();
	}

	return 0;

}