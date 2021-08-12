#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define MOD 1000000007
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
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

bool f(lo m, vector<vector<lo>>&v)
{
	lo cost = 0, para = 0;

	for(int i = 0; i < v.size(); i++)
	{
		if(m >= max(cost, v[i][0]))return true;
		else cost += v[i][1];
	}




	return (cost <= m);
}

void solve()
{
	lo n, r = 0; cin >> n; vector<vector<lo>>v(n, vector<lo>(2));

	for(int i = 0; i < n; i++)
	{
		cin >> v[i][0];
		r = max(r, v[i][0]);
	}

	for(int i = 0; i < n; i++)cin >> v[i][1];

	sort(allr(v));

	lo l = 0;

	while(l <= r)
	{
		lo m = (l + r) >> 1;

		// debug(l); debug(r); debug(r);

		if(f(m, v))r = m - 1;
		else l = m + 1;
	}

	cout << l << endl;
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