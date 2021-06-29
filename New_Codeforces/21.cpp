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


vector<vector<lo>> matrixPower(lo n)
{
	if(n == 0) return {{1,0},{0,1}};
	if(n == 1) return {{0,1},{1,1}};

	vector<vector<lo>>mat = matrixPower(n/2);

	vector<vector<lo>>temp(2, vector<lo>(2,0));

	temp[0][0] = mat[0][0]*mat[0][0] + mat[0][1]*mat[1][0];
	temp[0][1] = mat[0][0]*mat[0][1] + mat[0][1]*mat[1][1];
	temp[1][0] = mat[1][0]*mat[0][0] + mat[1][1]*mat[1][0];
	temp[1][1] = mat[1][0]*mat[0][1] + mat[1][1]*mat[1][1];

	mat[0][0]  = temp[1][0];
	mat[0][1] = temp[1][1];
	mat[1][0] = temp[0][0] + temp[1][0];
	mat[1][1] = temp[0][1] + temp[1][1];


	if(1&n) return mat;

	return temp; 
}

void solve()
{
	lo x, y, n;  cin >> x >> y >> n;



	vector<vector<lo>>v = matrixPower(n-1);

	lo fn = v[0][0]*x + v[0][1]*y;
	lo fn1 = v[1][0]*x + v[1][1]*y;

	cout << fn << endl;

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