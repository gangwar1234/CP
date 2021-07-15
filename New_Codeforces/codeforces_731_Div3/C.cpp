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
	lo k, n, m; cin >> k >> n >> m; vl a(n), b(m); cin >> a >> b;

	lo ptr1 = 0, ptr2 = 0;

	vector<lo>res;

	// debug(k);
	// debug(n);
	// debug(m);

	while(ptr1 < n || ptr2 < m)
	{
		// debug(ptr1);
		// debug(ptr2);
		// debug(k);
		if(ptr1 == n)
		{
			if(b[ptr2]  > k){cout << -1 << endl; return;}
			if(b[ptr2] == 0)k++;
			res.push_back(b[ptr2++]);
			continue;
		}

		if(ptr2 == m)
		{
			if(a[ptr1]  > k){cout << -1 << endl; return;}
			if(a[ptr1] == 0)k++;
			res.push_back(a[ptr1++]);
			continue;
		}

		if(a[ptr1] < b[ptr2])
		{
			if(a[ptr1] > k){cout << -1 << endl; return;}
			if(a[ptr1] == 0)k++;
			res.push_back(a[ptr1++]);
		}
		else
		{
			if(b[ptr2] > k){cout << -1 << endl; return;}
			if(b[ptr2] == 0)k++;
			res.push_back(b[ptr2++]);			
		}

	}

	for(auto x : res)cout << x << " ";

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