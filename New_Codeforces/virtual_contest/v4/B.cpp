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
	lo n; cin >> n; vl v(n); cin >> v;

	vector<vector<lo>>m;

	for(int i = 1; i < n; i++)
	{
		lo y = v[i] - v[0];
		lo x = i;
		lo g = gcd(x,y);

		y/=g;
		x/=g;

		m.push_back({y,x});
	}

	for(int i = 0; i < m.size(); i++)
	{
		auto a = m[i];

		map<lo,bool>mp;
		mp[0] = true;

		for(int j = 1; j < n; j++)
		{
			lo y = v[j] - v[0];
			lo x = j;
			lo g = gcd(x,y);

			y/=g;
			x/=g;

			if(y == a[0] && x == a[1]){mp[j] = true;}
		}

		lo fr = INT_MIN, sc = INT_MIN; vl t = {INT_MIN,INT_MIN};

		bool flag = true;

		for(int j = 0; j < n; j++)
		{
			if(mp.count(j) == 0)
			{
				if(fr == INT_MIN)
				{
					fr = v[j];
					sc = j;
				}
				else
				{
					if(t[0] == INT_MIN)
					{
						lo y = v[j] - fr;
						lo x = j - sc;
						lo g = gcd(x,y);

						y/=g;
						x/=g;	

						if(y != t[0] || x != t[1])
						{
							flag = false;
							break;
						}					
					}
				}
			}
		}

		if(flag)
		{
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
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