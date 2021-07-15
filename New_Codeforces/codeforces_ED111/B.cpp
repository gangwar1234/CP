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
	lo n, a, b; cin >> n >> a >> b;

	string s; cin >> s;

	if(b > 0)
	{
		cout << n*(a+b) << endl; return;
	}

	lo cnt0 = 0, cnt1 = 0;

	bool zero = false, one = false;

	if(s[0] == '0')zero = true; else one = true;

	for(int i = 1; i < n; i++)
	{
		if(s[i] != s[i-1])
		{
			if(s[i-1] == '0'){cnt0++; one = true; zero = false;}
			else {cnt1++; zero = true; one = false;}
		}
	}

	if(one)cnt1++; if(zero)cnt0++;

	// cout << cnt0 << " " << cnt1 << endl;

	cout << (min(cnt0, cnt1) + 1)*b + n*a << endl;

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