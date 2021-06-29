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

vector<lo>fact(11);

void factFind()
{
	fact[0] = 1;

	for(lo i = 1; i <= 10; i++)fact[i] = fact[i-1]*i;
}

void solve()
{
	factFind();

	string a, b; cin >> a >> b;

	lo pos1 = 0, neg1 = 0, ques = 0, pos2 = 0, neg2 = 0;

	for(auto c : a)if(c == '+')pos1++; else neg1++;

	for(auto c : b)if(c == '+')pos2++; else if(c == '-')neg2++; else ques++;

	lo x = pos1 - pos2, y = neg1 - neg2;

	if(x < 0 || y < 0 || x + y != ques)
	{
		cout << fixed << setprecision(12) << (double)0;

		return;
	}

	cout << fixed << setprecision(12) << (double)fact[ques]/(fact[x]*fact[y])/(pow(2,(x+y)));
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