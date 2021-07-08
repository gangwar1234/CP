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
	int n, gcd_v = 0; cin >> n; vector<int> v(n); cin >> v;

	int max_e = *max_element(v.begin(), v.end());

	vector<int>res(1, max_e);

	gcd_v = max_e;

	sort(v.rbegin(), v.rend());

	v.erase(find(v.begin(), v.end(), max_e));

	while(res.size() < n)
	{
		int m = v.size(), val, g = 0;

		for(int i = 0; i < m; i++)
		{
			if(g < gcd(gcd_v, v[i]))
			{
				g = gcd(gcd_v , v[i]);
				val = v[i];
			}
		}

		v.erase(find(v.begin(), v.end(),val));
		res.push_back(val);
		gcd_v = g;
	}

	for(int i = 0; i < res.size(); i++)cout << res[i] << " ";

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