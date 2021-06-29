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

lo dfs(lo start, vector<vector<vector<lo>>>&g, lo parent, vector<lo>&w, lo &res)
{

	lo first = 0, second = 0, sum = 0;

	for(auto child : g[start])
	{
		if(child[0] != parent){

			lo val = max((child[1] + dfs(child[0], g, start, w, res)), 0LL);

			if(first < val){
				second = first;
				first = val;
			}
			else{
				second = max(second, val);
			}
		}
	}

	res = max(res, first + second + w[start]);

	sum = w[start] + first;

	res = max(res, sum);

	return sum;
}



void solve()
{
	lo n, x, y, c, res = 0;  cin >> n;  vl w(n); cin >> w;

	vector<vector<vector<lo>>> g(n);

	vector<lo>dp(n, -1);

	REP(0, n-1){
		cin >> x >> y >> c; x--; y--;
		g[x].push_back({y, -c});
		g[y].push_back({x, -c});
	}

	dfs(0, g, -1, w, res);

	cout << res << endl;
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