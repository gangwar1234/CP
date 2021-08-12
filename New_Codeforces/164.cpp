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

bool cmp(vector<lo>&a, vector<lo>&b)
{
	return (a[1] < b[1]);
}

void solve()
{
	lo n, r, avg, s = 0; cin >> n >> r >> avg;
	vector<vector<lo>>v(n, vector<lo>(2));

	for(int i = 0; i < n; i++)
	{
		cin >> v[i][0] >> v[i][1];
		s += v[i][0];
	}

	sort(v.begin(), v.end(), cmp);

	lo sum = max(0LL, avg*n - s), cost = 0; 

	for(int i = 0; i < n; i++)
	{
		cost += (min(r - v[i][0], sum))*v[i][1];
		sum -= min(r-v[i][0], sum);

		if(sum == 0)break;
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