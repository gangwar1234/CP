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

lo dfs(lo start, vector<vector<lo>>&g, lo parent, vector<lo>&edge, vector<lo>&childCnt)
{
	lo ch = 1;
	
	for(auto child : g[start])
	{
		if(child == parent)continue;
		ch += dfs(child,g,start, edge, childCnt);
	}

	childCnt[start] = ch;

	return childCnt[start];
}

void dfs3(lo start, vector<vector<lo>>&g, lo parent, vector<lo>&edge, vector<lo>&childCnt)
{

	lo total = g.size()-1;

	for(auto child : g[start])
	{
		if(child == parent)continue;
		if(total == 2*childCnt[child])
		{
			edge[0] = start;
			edge[1] = child;
		}
		else
			dfs3(child,g,start, edge, childCnt);
	}

}

void solve()
{
	lo n, x, y; cin >> n; vector<vector<lo>>v(n+1);

	for(int i = 0; i < n-1; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	vector<lo>child(n+1, 0);

	vector<lo>edge={-1,-1};

	dfs(1, v, -1, edge, child);
	dfs3(1, v, -1, edge, child);

	if(edge[0] == -1 && edge[1] == -1)
	{
		cout << 1 << " " << v[1][0] << endl;
		cout << 1 << " " << v[1][0] << endl;
		return;
	}

	for(int i = 0; i < v[edge[0]].size(); i++)
	{
		if(v[edge[0]][i] != edge[1])
		{
			cout << edge[0] << " " << v[edge[0]][i] << endl;
			cout << v[edge[0]][i] << " " << edge[1] << endl; 
			return;
		}
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