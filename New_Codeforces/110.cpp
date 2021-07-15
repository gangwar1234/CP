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
	lo n, k, ptr = 0; cin >> n >> k; vl a(n); cin >> a; 
	vl w(k); cin >> w;

	sort(a.rbegin(), a.rend());
	sort(w.begin(), w.end());

	vector<vector<lo>>weight(k, vector<lo>(2));

	for(int i = 0; i < k; i++)
	{
		weight[i][0] = a[ptr++];
		weight[i][1] = weight[i][0];
		w[i]--;
	}

	for(int i = 0; i < k; i++)
	{
		// debug(ptr);
		// debug(w[i]);

		if(w[i])
		{
			weight[i][1] = a[ptr+w[i]-1];
			ptr+= (w[i]);
		}
	}

	lo res = 0;

	for(int i = 0; i < k; i++)
	{
		res += (weight[i][0] + weight[i][1]);
	}

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

	lo T; cin >>T;

	while(T--)
	{
		solve();
	}

	return 0;

}