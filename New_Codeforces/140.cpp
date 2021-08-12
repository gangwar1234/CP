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
	lo n, max_idx, min_idx; cin >> n; vl v(n); cin >> v;

	lo max_e = *max_element(v.begin(), v.end());

	lo l1 = max_e, r1 = n - max_e;

	lo l2 = n - max_e, r2 = max_e;

	vector<lo>a(n, 0);

	for(int i = 0; i < max_e; i++)a[v[i]]++;

	bool flaga = true, flagb = true;

	for(int i = 1; i <= max_e; i++)
	{
		if(a[i] == 0)
		{
			flaga = false;
		}
	} 

	a = vector<lo>(n,0);

	for(int i = max_e; i < n; i++)a[v[i]]++;
	
	for(int i = 1; i <= n - max_e; i++)
	{
		if(a[i] == 0)flaga = false;
	}	

	a = vector<lo>(n, 0);

	for(int i = 0; i < n - max_e; i++)a[v[i]]++;

	for(int i = 1; i <= n - max_e; i++)
	{
		if(a[i] == 0)
		{
			flagb = false;
		}
	} 

	a = vector<lo>(n,0);

	for(int i = n-max_e; i < n; i++)a[v[i]]++;
	
	for(int i = 1; i <= max_e; i++)
	{
		if(a[i] == 0)flagb = false;
	}

	vector<vector<lo>>res;

	if(flaga)res.push_back({l1, r1});
	if(flagb && !(l1 == l2 && r1 == r2))res.push_back({l2, r2});

	cout << res.size() << endl;

	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i][0] << " " << res[i][1] << endl;
	}
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