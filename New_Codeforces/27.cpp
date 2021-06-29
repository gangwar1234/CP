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
	lo n, l = -1, r = -1; cin >> n; vl v(n); cin >> v;

	cin >> v;

	unordered_map<lo, lo>m;

	REP(0, n)
	{
		m[v[i]] = i + 1;
	}

	sort(v.begin(), v.end());

	REP(0, n)
	{
		if(m[v[i]] != i+1)
		{
			l = i;
			break;
		}
	}

	for(int i = n - 1; i >= 0; i--)
	{
		if(m[v[i]] != i+1)
		{
			r = i;
			break;
		}
	}

	if(l == -1 && r == -1)
	{
		cout << "yes" << endl << 1 << " " << 1; return;
	}

	// cout << l << " " << r << endl;

	reverse(v.begin()+l, v.begin()+r+1);

	// for(int i = 0; i < n; i++)cout << v[i] << " ";

	// cout << endl;

	for(int i = l; i <= r; i++)
	{
		if(m[v[i]]!= i+1)
		{
			cout << "no" << endl; return;
		}
	}

	cout << "yes" << endl << l + 1 << " " << r + 1 << endl;

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