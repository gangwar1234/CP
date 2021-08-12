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

vector<bool>prime(1001, true);
vector<lo>primeDiv(1001,0);
unordered_map<lo, lo>m;

void seive()
{

	for(int i = 2; i*i < 1001; i++)
	{
		if(!prime[i])continue;

		primeDiv[i] = i;

		for(int j = 2*i; j < 1001; j+=i)
		{
			prime[j] = false;

			if(primeDiv[j] == 0)primeDiv[j] = i;
		}
	}
}

void solve()
{
	lo n, color = 1; cin >> n; vl v(n); cin >> v;

	unordered_map<lo,lo>colorPr; vl res;

	for(int i = 0; i < n; i++)
	{
		if(colorPr[primeDiv[v[i]]] == 0)
		{
			colorPr[primeDiv[v[i]]] = color++;
		}

		res.push_back(colorPr[primeDiv[v[i]]]);
	}

	cout << color-1 << endl;

	for(int i = 0; i < n; i++)cout << res[i] << " ";

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

	seive();

	while(T--)
	{
		solve();
	}

	return 0;

}