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
	lo n, x; cin >> n;

	unordered_map<lo,vector<lo>>m;

	for(int i = 0; i < n; i++)
	{
		cin >> x;
		m[x].push_back(i);
	}

	vector<vector<lo>>res;

	for(auto a : m)
	{
		auto x = a.first;
		auto y = a.second;

		if(y.size() == 1){res.push_back({x,0}); continue;} 

		bool flag = true;

		for(int i = 2; i < y.size(); i++)
		{
			if(y[i] - y[i-1] != y[1] - y[0])
			{
				flag = false; break;
			}
		}

		if(flag)
		{
			res.push_back({x, y[1]-y[0]});
		}
	}

	cout << res.size() << endl;

	sort(res.begin(), res.end());

	for(auto a : res)
	{
		auto x = a[0], y = a[1];
		cout << x << " " << y << endl;
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