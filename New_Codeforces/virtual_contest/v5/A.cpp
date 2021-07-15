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
	lo n, op = 0, j = 0, sum1 = 0, sum2 = 0; cin >> n; vl a(n), b(n); cin >> a >> b;

	vector<vector<lo>>moreIdx;

	for(int i = 0; i < n; i++)
	{
		if(a[i] > b[i])
		{
			moreIdx.push_back({i + 1, a[i]-b[i]});
			op += (a[i] - b[i]);
		}
	}


	sum1 = accumulate(a.begin(), a.end(), 0);
	sum2 = accumulate(b.begin(), b.end(), 0);

	if(sum1 != sum2)
	{
		cout << -1 << endl; return;
	}

	cout << op << endl;

	for(int i = 0; i < n; i++)
	{
		while(a[i] < b[i])
		{
			if(moreIdx[j][1] == 0)j++;
			cout << moreIdx[j][0] << " " << i + 1 << endl;
			moreIdx[j][1]--;
			a[i]++;
			a[moreIdx[j][0]-1]--;
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