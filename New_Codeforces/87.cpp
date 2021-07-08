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
	lo n, x; cin >> n; 
	vector<vector<lo>>v(6);

	for(int i = 0; i < n; i++)
	{
		cin >> x;
		if(x == 4)v[0].push_back(i);
		else if(x == 8)v[1].push_back(i);
		else if(x == 15)v[2].push_back(i);
		else if(x == 16)v[3].push_back(i);
		else if(x == 23)v[4].push_back(i);
		else if(x == 42)v[5].push_back(i);
	}

	lo x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, cnt = 0;

	// for(auto a : v[0])cout << a << " ";
	// cout << endl;

	// for(auto a : v[1])cout << a << " ";
	// cout << endl;

	// for(auto a : v[2])cout << a << " ";
	// cout << endl;

	// for(auto a : v[3])cout << a << " ";
	// cout << endl;

	// for(auto a : v[4])cout << a << " ";
	// cout << endl;

	// for(auto a : v[5])cout << a << " ";
	// cout << endl;

	while(1)
	{
		if(x1 >= v[0].size())break;
		x1++;

		while(x2 < v[1].size() && v[1][x2] < v[0][x1-1])x2++;
		if(x2 >= v[1].size())break;
		x2++;

		while(x3 < v[2].size() && v[2][x3] < v[1][x2-1])x3++;
		if(x3 >= v[2].size())break;
		x3++;

		while(x4 < v[3].size() && v[3][x4] < v[2][x3-1])x4++;
		if(x4 >= v[3].size())break;
		x4++;

		while(x5 < v[4].size() && v[4][x5] < v[3][x4-1])x5++;
		if(x5 >= v[4].size())break;
		x5++;

		while(x6 < v[5].size() && v[5][x6] < v[4][x5-1])x6++;
		if(x6 >= v[5].size())break;
		x6++;

		cnt++;
		// debug(cnt);
	}



	cout << (n-6*cnt) << endl;
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