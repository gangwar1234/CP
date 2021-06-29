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

bool f(lo m, vector<lo>&v, lo k)
{

	lo sum = 0, n = v.size();

	for(int i = n/2; i < n; i++)
	{
		if(v[i] < m)
		{
			sum+=(m-v[i]);
		}
	}

	return (sum <= k);

}


void solve()
{
	lo n, k; cin >> n >> k; vl v(n); cin >> v;

	sort(v.begin(), v.end());

	lo l = v[n/2], r = 2000000007;

	while(l <= r)
	{
		lo m = (l + r)>>1;

		if(f(m, v, k))
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}

	cout << r << endl;
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