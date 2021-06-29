#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define MOD 1000000007
#define MAX 200005
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

lo dfs(lo start, unordered_map<lo, vector<lo>>&g, vector<lo>&visited)
{
	visited[start] = true;

	lo ch = 1;

	for(auto child : g[start])
	{

		if(!visited[child])
		ch += dfs(child,g,visited);
	}

	return ch;
}



void solve()
{
	lo N, cnt = 0; 	cin >> N;	vector<lo>v(N);

	unordered_map<lo, vector<lo>>g;

	for(int i = 0; i < N; i++) cin >> v[i];

	for(int i = 0; i < N/2; i++)
	{
		g[v[i]].push_back(v[N-i-1]);
		g[v[N-i-1]].push_back(v[i]);
	}

	vector<lo>visited(MAX,0);

	for(int i = 0; i < N; i++)
	{
		if(!visited[v[i]])
		{

			lo val = (dfs(v[i], g,visited));
			cnt += (val-1);
		}
	}	

	cout << cnt << endl;
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