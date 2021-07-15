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
	lo m, s, i = 0; cin >> m >> s;

	if(9*m < s || (m > 1 && s == 0)){cout << "-1 -1" << endl; return;}

	lo nines = s/9;
	lo others = s%9;

	string max = string(nines, '9');

	if(others)max += (others+'0');

	while(max.length() < m)max += "0";

	string min = "";

	s -= 1;

	nines = s/9;
	others = s%9;

	debug(others);

	for(int i = m-1; i >= 1; i--)
	{
		if(nines > 0){min = "9" + min; nines--;}
		else if(others > 0){min = string(1, others + '0') + min; others = 0;}
		else min = "0" + min;
	}

	min = string(1, others + 1 + '0') + min;

	cout << min << " " << max << endl;
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