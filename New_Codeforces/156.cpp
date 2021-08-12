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

void fill(vector<vector<lo>>&cnt, lo i, string &s, lo n)
{
	lo count = 0;

	for(int j = 0; j < s.length(); j++)
	{
		count += (s[j] - 'a' == i);
	}

	cnt[i][n] += (2*count - s.length());
}


void solve()
{
	lo n, k, res = 0; cin >> n;

	string s;

	vector<vector<lo>>cnt(5, vector<lo>(n));

	for(int i = 0; i < n; i++)
	{
		cin >> s;

		for(int j = 0; j < 5; j++)
			fill(cnt, j, s, i);
	}

	// for(int i = 0; i < 5; i++)
	// {
	// 	for(int j = 0; j < n; j++)cout << cnt[i][j] << " ";
	// 	cout << endl;
	// }

	sort(cnt[0].rbegin(), cnt[0].rend());
	sort(cnt[1].rbegin(), cnt[1].rend());
	sort(cnt[2].rbegin(), cnt[2].rend());
	sort(cnt[3].rbegin(), cnt[3].rend());
	sort(cnt[4].rbegin(), cnt[4].rend());

	for(int i = 0; i < 5; i++)
	{
		lo sum = 0;

		for(int j = 0; j < n; j++)
		{
			sum += cnt[i][j];
			if(sum <= 0)break;
			res = max(res, (lo)(j + 1));
		}
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