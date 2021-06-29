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
	lo n; cin >> n;  vector<lo>a(n);

	vector<vector<lo>>v(n, vector<lo>(n));

	vector<lo>sum(n+1);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> v[i][j];
		}
	}

	for(int m = 0; m < n-2; m++){

		a[m] = sqrt(v[m][n-1]*v[m][n-2]/v[n-1][n-2]);
	}

	a[n-2] =  sqrt(v[n-2][0]*v[n-2][n-1]/v[0][n-1]);
	a[n-1] =  sqrt(v[n-1][0]*v[n-1][1]/v[0][1]);

	for(int i = 0; i < n; i++)cout << a[i] << " ";
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

	lo T; T=1;

	while(T--)
	{
		solve();
	}

	return 0;

}