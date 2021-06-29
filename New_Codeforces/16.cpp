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

vector<bool>prime(1007,true);

void seive()
{
	for(int i = 2; i * i < 1007; i++)
	{
		if(!prime[i])continue;

		for(int j = 2*i; j < 1007; j+=i)
		{
			prime[j] = false;
		}
	}
}


void solve()
{
	string s; cin >> s;

	seive();

	lo n = s.length(), non_equal = 1;

	vector<lo>v(26);  unordered_map<lo, lo>prime_idx;

	prime_idx[0] = true;

	for(int i = 2; i < n+1; i++)
	{
		if(prime[i] && i*2 > n)
		{
			non_equal++;
			prime_idx[i-1] = true;
		}
	}

	lo equal = n - non_equal;

	for(auto a : s)v[a-'a']++;

	lo max_val = *max_element(v.begin(), v.end());
	lo max_idx = max_element(v.begin(), v.end()) - v.begin();
	
	if(max_val < equal)
	{
		cout << "NO";
		return;
	}

	cout << "YES" << endl;

	string res = s;

	for(int i = 1; i < n; i++)
	{
		if(prime_idx.find(i) == prime_idx.end())
		{
			res[i] = (char)(max_idx+'a');
			v[max_idx]--;
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(prime_idx.find(i) != prime_idx.end())
		{
			for(int j = 0; j < 26; j++)
			{
				if(v[j] > 0)
				{
					res[i] = (char)(j+'a');
					v[j]--;
					break;
				}
			}
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

	lo T; T=1;

	while(T--)
	{
		solve();
	}

	return 0;

}