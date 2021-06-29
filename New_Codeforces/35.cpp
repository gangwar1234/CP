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
	lo n; cin >> n; lo res = n, res_a = 1, res_b = n-1;

	for(int i = 2; i * i <= n; i++)
	{
		if(n%i == 0)
		{
			lo a = n/i, b = i;

			lo sc = n/a, fr = (a - 1)*sc;

			// cout << " sc : " << sc << " fr : " << fr << endl;

			// cout << (sc*fr)/gcd(sc,fr) << endl;

			// cout << " res : " << res << endl;

			if(res > (sc*fr)/gcd(sc, fr))
			{
				res = (sc*fr)/gcd(sc, fr);
				res_a = fr;
				res_b = sc; 
			}

			sc = n/b, fr = (b-1)*sc;

			// cout << " sc : " << sc << " fr : " << fr << endl;

			if(res > (sc*fr)/gcd(sc, fr))
			{
				res = (sc*fr)/gcd(sc, fr);
				res_a = fr;
				res_b = sc; 
			}

			// cout << " res : " << res << endl;
		}
	}

	cout << res_a << " " << res_b << endl;
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