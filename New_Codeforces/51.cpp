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

void clear(queue<lo>&q, lo k, lo i)
{
	while(q.size() && i - q.front() >= k)q.pop();
}

void solve()
{
	lo n, k, t = 0, l = 0; cin >> n >> k; vl v(n); cin >> v;

	queue<lo>q;

	for(int i = 2; i < k; i++)
	{
		if(v[i-1] > v[i-2] && v[i-1] > v[i])q.push(i-2);
	}

	if(q.size() > t)
	{
		t = q.size();
		l = 0;
	}

	int i = k;

	while(i < n)
	{
		clear(q, k, i);
		if(v[i-1] > v[i-2] && v[i-1] > v[i])q.push(i-2);
		if(q.size() > t)
		{
			t = q.size();
			l = i-k+1;
		}
		i++;
	}

	cout << t + 1 << " " << l+1 << endl;
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