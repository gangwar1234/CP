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

void superior(vl &a, vl &mv, lo &res, lo i)
{
	lo cnt = 0;

	if(a[0] < mv[0])cnt++;
	if(a[1] < mv[1])cnt++;
	if(a[2] < mv[2])cnt++;
	if(a[3] < mv[3])cnt++;
	if(a[4] < mv[4])cnt++;

	if(cnt > 2)mv = a, res = i;
}

bool check(vl mv, vl a)
{
	lo cnt = 0;

	if(a[0] < mv[0])cnt++;
	if(a[1] < mv[1])cnt++;
	if(a[2] < mv[2])cnt++;
	if(a[3] < mv[3])cnt++;
	if(a[4] < mv[4])cnt++;

	if(cnt > 2)return false;
	return true;	
}

void solve()
{
	lo n, res; cin >> n; vl v(5), maxv(5, INT_MAX);

	vector<vector<lo>>x(n);

	for(int i = 0; i < n; i++)
	{
		cin >> v;
		x[i] = v;
		superior(v, maxv, res, i);
	}

	for(int i = 0; i < n; i++)
	{
		if(!check(maxv, x[i])){cout << -1 << endl; return;}
	}

	cout << (res+1) << endl;
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