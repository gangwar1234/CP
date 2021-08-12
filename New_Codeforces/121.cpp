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

string StringMake(deque<lo>a)
{
	string s = "";

	while(a.size())
	{
		s += to_string(a.front());
		a.pop_front();
	}

	return s;
}

void solve()
{
	lo n, cnt = 0; cin >> n;

	lo k1;  cin >> k1; vl a(k1); cin>> a;

	lo k2; cin >> k2; vl b(k2); cin >> b;

	unordered_map<string, bool>seen1, seen2;

	deque<lo>q1, q2;

	for(int i = 0; i < k1; i++)q1.push_back(a[i]);
	for(int i = 0; i < k2; i++)q2.push_back(b[i]);

	seen1[StringMake(q1)] = true;
	seen2[StringMake(q2)] = true;

	while(q1.size() && q2.size())
	{
		lo x = q1.front(); q1.pop_front();
		lo y = q2.front(); q2.pop_front();

		if(x < y)
		{
			q2.push_back(x);
			q2.push_back(y);
		}
		else
		{
			q1.push_back(y);
			q1.push_back(x);
		}

		if(seen1[StringMake(q1)] && seen2[StringMake(q2)])
		{
			cout << -1 << endl; return;
		}

		seen1[StringMake(q1)] = true;
		seen2[StringMake(q2)] = true;

		cnt++;
	}

	if(q1.size())cout << cnt << " " << 1 << endl;
	else cout << cnt << " " << 2 << endl;

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