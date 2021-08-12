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
	lo n, l, cnt = 0, r, x; cin >> n >> l >> r >> x; vl v(n); cin >> v;

	for(int i = 0; i < (1 << n); i++)
	{
		lo min_val = LLONG_MAX, max_val = LLONG_MIN;

		vl a;

		for(int j = 0; j < n; j++)
		{
			if((i&(1<<j)))
			{
				min_val = min(min_val, v[j]);
				max_val = max(max_val, v[j]);
				a.push_back(v[j]);
			}
		}

		if(a.size() > 1)
		{
			lo sum = accumulate(a.begin(), a.end(), 0);
			if(sum >= l && sum <= r && max_val - min_val >= x)
			{
				cnt++;

				// for(int j = 0; j < a.size(); j++)
				// {
				// 	cout << a[j] << " ";
				// }

				// cout << endl;
			}
		}
	}

	cout << cnt << endl;
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