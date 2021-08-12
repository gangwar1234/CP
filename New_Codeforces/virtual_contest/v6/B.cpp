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
	lo n, m, bit = 1; cin >> n >> m;

	vector<string>v(n, string(m, '0'));

	for(int i = 0; i < m; i+=2) v[0][i] = '1';
	

	for(int i = 2; i < n - 1; i+=2)
	{
		v[i][0] = '1';
		v[i][m-1] = '1';
	}

	if(1&n) for(int i = 0; i < m; i+=2)v[n-1][i] = '1';
	
	vector<string>v1(n, string(m, '0'));

	for(int i = 1; i < m; i+=2) v1[0][i] = '1';
	
	for(int i = 2; i < n - 1; i+=2)
	{
		v1[i][0] = '1';
		v1[i][m-1] = '1';
	}

	if(1&n) for(int i = 1; i < m; i+=2)v1[n-1][i] = '1';

	lo cnt1 = 0, cnt2 = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)if(v[i][j] == '1')cnt1++;
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)if(v1[i][j] == '1')cnt2++;
	}

	if(cnt1 > cnt2)
	{
		for(int i = 0; i < n; i++)cout << v[i] << endl;
	}
    else
    {
    	for(int i = 0; i < n; i++)cout << v1[i] << endl;
    }

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