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
	lo n, k, idx = 0, m; cin >> n >> k;

	deque<lo>qPow;	m = n;

	while(n)
	{
		if(n%2)qPow.push_back(idx);
		n/=2;
		idx++;
	}


	if(m < k || qPow.size() > k)
	{  
		cout << "NO" << endl; return;
	}

	while(qPow.size() < k)
	{

		lo a = qPow.front();
		qPow.pop_front();

		if(a > 1){qPow.push_front(a-1); qPow.push_front(a-1);}
		else 
		{
			if(a == 1) qPow.push_back(0); 
			qPow.push_back(0);
		}
	}

	cout << "YES" << endl;

	while(qPow.size())
	{
		cout << pow(2,qPow.front()) << " ";
		qPow.pop_front();
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

	lo T; T = 1;

	while(T--)
	{
		solve();
	}

	return 0;

}