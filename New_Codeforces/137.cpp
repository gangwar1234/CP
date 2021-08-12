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

bool f(lo m, vector<lo>&v, lo sum)
{
	lo diff = 0;

	for(int i = 0; i < v.size(); i++)
	{
		diff += abs(v[i] - m);
	}

	return (2*diff <= sum);
}


void solve()
{
	lo n, x, sOdd = 0, sEven = 0; cin >> n; vl v(n);

	for(int i = 0; i < n; i++)
	{
		cin >> x;

		if(1&(i+1))sOdd += x;
		else sEven += x;

		v[i] = x;
	}


	if(2*sOdd <= (sOdd + sEven))
	{
		int i = 0;

		for(i = 0; i < n-1; i+=2)
		{
			cout << 1 << " " << v[i+1] << " ";
		}

		if(i <= n-1)cout << 1;
	}
	else
	{
		int i = 0;

		for(i = 0; i < n-1; i+=2)
		{
			cout << v[i] << " " << 1 << " ";
		}

		if(i <= n-1)cout << v[n-1];		
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