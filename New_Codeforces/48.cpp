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
	lo n, X, cnx = 0; cin >> n;

	vector<vector<lo>>fact;

	X = sqrt(n); 

	while(n%2==0)
	{
		cnx++;
		n/=2;
	}

	if(cnx)
	{
		fact.push_back({cnx, 2});
	}

	for(int i = 3; i <= X; i++)
	{
		lo cnt = 0;

		while(n%i == 0)
		{
			n/=i;
			cnt++;
		}

		if(cnt){fact.push_back({cnt, i});}
	}

	if(n > 2)
	{
		fact.push_back({1, n});
	}

	sort(fact.rbegin(), fact.rend());

	vector<lo>res(fact[0][0],1);

	for(int i = 0; i < fact.size(); i++)
	{
		lo j = res.size() - 1; 

		while(j >= 0 && fact[i][0] > 0)
		{
			res[j] *= fact[i][1];
			fact[i][0]--;
			j--;
		}
	}

	cout << res.size() << endl;

	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}

	cout << endl;
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