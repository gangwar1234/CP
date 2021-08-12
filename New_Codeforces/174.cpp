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
	lo h, w; cin >> h >> w; vl r(h), c(w); cin >> r >> c;

	vector<vector<lo>>mat(h, vector<lo>(w));

	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < r[i]; j++)
		{
			mat[i][j] = 1;
		}
	}


	for(int i = 0; i < w; i++)
	{
		for(int j = 0; j < c[i]; j++)
		{
			mat[j][i] = 1;
		}
	}

	for(int i = 0; i < h; i++)
	{
		lo cnt = 0;

		for(int j = 0; j < w && mat[i][j] == 1; j++)
		{
			cnt++;
		}

		if(cnt != r[i]){cout << 0 << endl; return;}
	}

	for(int i = 0; i < w; i++)
	{
		lo cnt = 0;

		for(int j = 0; j < h && mat[j][i] == 1; j++)
		{
			cnt++;
		}

		if(cnt != c[i]){cout << 0 << endl; return;}
	}

	lo res = 0;

	for(int i = 1; i < h; i++)
	{
		for(int j = 1; j < w; j++)
		{
			if(c[j] < i && r[i] < j)res++;
		}
	}

	cout << power(2, res)%MOD << endl;
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