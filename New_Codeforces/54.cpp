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
	lo n, cnt = 0; cin >> n; string a, b; cin >> a >> b;

	vector<lo>res;

	for(int i = n - 1; i >= 0; i--)
	{
		if(a[i] == b[i])continue;

		if(a[0] != a[i])
		{
			res.push_back(1);
			if(a[0] == '0')a[0] = '1';
			else a[0] = '0';

			// cout << "at 0 index a : " << a << endl;

		}
		res.push_back(i+1);
		
		for(int j = 0; j <= i; j++)if(a[j] == '0')a[j] = '1'; else a[j] = '0';
		reverse(a.begin(), a.begin()+i+1);

		// cout << "at " << i << " index a : "<< a << endl;
	}

	cout << res.size() << " ";

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