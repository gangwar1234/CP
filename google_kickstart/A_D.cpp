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
	lo g00, g01, g02, g10, g12, g20, g21, g22, g11;

	cin >> g00 >> g01 >> g02 >> g10 >> g12 >> g20 >> g21 >> g22;

	unordered_map<lo, lo>m;

	lo a = g22 + g00;
	lo b = g02 + g20;
	lo c = g12 + g10;
	lo d = g01 + g21;

	if(a%2 == 0)m[a/2]++;
	if(b%2 == 0)m[b/2]++;
	if(c%2 == 0)m[c/2]++;
	if(d%2 == 0)m[d/2]++;

	lo x, freq = 0;

	for(auto t : m)
	{
		if(freq < t.second)
		{
			x = t.first;
			freq = t.second;
		}
	}

	// debug(x);


	if(g01-g00 == g02-g01)freq++;
	if(g21-g20 == g22-g21)freq++;
	if(g10-g00 == g20-g10)freq++;
	if(g12-g02 == g22-g12)freq++;

	cout << freq << endl;
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

	lo T, i = 1; cin >>T;

	while(T--)
	{
		cout << "Case #"<<i<<":";
		solve();
		i++;
	}

	return 0;

}