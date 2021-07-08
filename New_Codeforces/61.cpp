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
	lo n, m, cost = 0;	cin >> n >> m; 
	vector<vector<lo>>v(n, vector<lo>(m));

	lo row = ceil((double)n/2);
	lo col = ceil((double)m/2);

	for(int i = 0; i < n; i++)cin >> v[i];

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			vector<lo>a;
			
			if(i < n-i-1)
			{	
				a.push_back(v[n-i-1][j]);

				if(m-j-1 >= 0)a.push_back(v[n-i-1][m-j-1]);
			}

			a.push_back(v[i][j]);

			if(j < m-j-1)a.push_back(v[i][m-j-1]);

			sort(a.begin(), a.end());
			lo N = a.size();
			lo med = a[N/2];

			for(int k = 0; k < N; k++)
			{
				cost+= abs(a[k] - med);
			}
		}
	}

	cout << cost << endl;
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