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
	string s; cin >> s;	lo left = -1, right = -1;

	for(int i = 0; i < s.length(); i++)if(s[i] == 'a'){left = i, right = i; break;}

	if(left == -1)
	{
		cout << "NO" << endl; return;
	}

	// debug(left);
	// debug(right);

	lo n = s.length(), i = 0;

	while(left >= 0 && right < n)
	{
		i++;

		if(left == 0 && right == n-1)break;

		if(left - 1 < 0)
		{
			if(s[right + 1] != (char)(i+'a'))
			{
				cout << "NO" << endl; return;
			}
			right++; continue;
		}
		else if(right + 1 == n)
		{
			if(s[left - 1] != (char)(i+'a'))
			{
				cout << "NO" << endl; return;
			}	
			left--;	continue;	
		}

		if(s[left - 1] == (char)(i+'a'))left--;
		else if(s[right + 1] == (char)(i+'a'))right++;
		else 
		{
			cout << "NO" << endl; return;
		}
	}

	cout << "YES" << endl;
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