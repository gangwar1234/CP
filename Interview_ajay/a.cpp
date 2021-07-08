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


int solve(vector<int>&ar, int n)
{
    int mx = 1e7 ;
    bool seen[mx] = {};
    set<int> cur;
    for(int i = 0; i < n; i++) {
        seen[ar[i]] = true;
set<int> temp;
for(int x : cur) {
seen[x] = true;
    temp.insert(x | ar[i]);
}
temp.insert(ar[i]);
cur = temp;
}
for(int x : cur) seen[x] = true;
int ans = 0;
for(int i = 0; i < n; i++) if(seen[i])ans++;
 return ans;
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
		int N;

		cin >> N;

		vector<int>ar(N);

		for(int i = 0; i < N; i++)
		{
			cin >> ar[i];
		}

		cout << solve(ar, N) << endl;
	}

	return 0;

}