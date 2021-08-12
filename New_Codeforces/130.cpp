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

	unordered_map<lo, lo>m;

	for(int i = 0; i < n; i++)
	{
		cin >> x;
		m[x]++;
	}

	lo cnt4 = 0, cnt2 = 0;

	for(auto a : m)
	{
		cnt4 += (a.second/4);
		cnt2 += (a.second/2);
	}

	lo q; cin >> q;
	
	while(q--)
	{
		char ch; lo num;

		cin >> ch >> num;

		cnt2 -= (m[num]/2);
		cnt4 -= (m[num]/4);

		if(ch == '+')m[num]++;
		if(ch == '-')m[num]--;

		cnt2 += (m[num]/2);
		cnt4 += (m[num]/4);

		if(cnt2 >= 4 && cnt4 >= 1) cout << "YES" << endl;
		else cout << "NO" << endl;
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

	lo T; T = 1;

	while(T--)
	{
		solve();
	}

	return 0;

}