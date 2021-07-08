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
	string s, t, p; cin >> s >> t >> p;

	lo n = t.length(), m = s.length(), l = p.length();

	vector<vector<lo>>freq(n+1, vector<lo>(26,-1));

	for(int i = n-1; i >= 0; i--)
	{
		freq[i] = freq[i+1];
		freq[i][t[i]-'a'] = i+1;
	}


	lo pos = 0, i = 0;

	while(i < m)
	{
		pos = freq[pos][s[i++]-'a'];

		// cout << " pos : "<< pos << endl;

		if(pos == -1)
		{
			cout << "NO" << endl; return;
		}
	}

	vector<lo>a(26), b(26), c(26);

	for(int i = 0; i < n; i++)a[t[i]-'a']++;
	for(int i = 0; i < m; i++)b[s[i]-'a']++;
	for(int i = 0; i < l; i++)c[p[i]-'a']++;

	for(int i = 0; i < 26; i++)a[i]-=b[i];

	// for(int i = 0; i < 26; i++)cout << a[i] <<  endl;	

	for(int i = 0; i < 26; i++)
	{
		if(a[i] > c[i]){
		cout << "NO" << endl; return;}
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