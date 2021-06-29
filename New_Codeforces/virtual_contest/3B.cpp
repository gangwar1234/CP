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

bool f(lo m, vector<lo>&v, lo s){
	
	lo cnt = 0;

	for(auto a : v){
		if(a < m)return false;
		cnt += max(0LL, a-m);
	}

	return (cnt >= s);
}

void solve()
{
	lo n, s; cin >> n >> s;	vector<lo>v(n);

	cin >> v;

	lo sum = 0;

	for(auto a : v)sum += a;

	if(sum < s){
		cout << -1; return;
	}

	lo l = 1, r = 1000000000000000000, m;

	while(l<=r){

		m = (l+r)>>1;

		// debug(l);
		// debug(r);

		if(f(m,v,s)){
			l = m + 1;
		}
		else{
			r = m - 1;
		}
	}
	
	if(f(r, v, s))cout << r << endl;
	else cout << -1 << endl;
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