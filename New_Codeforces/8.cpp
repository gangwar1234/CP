#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
#define MAX 10000007
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

vector<bool>prime(MAX+1, true);
vector<lo>primes(MAX+1);

void seive(){

	primes[0] = 1; primes[1] = 1;

	for(int i = 2; i < MAX; i++)primes[i] = i;

	for(lo i = 2; i * i < MAX; i++)
	{

		if(!prime[i])continue;

		for(lo j = i*i; j < MAX; j+=i)
		{
			prime[j] = false;
			primes[j]=i;
		}
	}
}

void primesPow(lo n, vector<lo>&v, vector<lo>&in)
{
	lo a, b;

	for(int i = 0; i < n; i++)
	{
		cin >> a;	in.push_back(a);
		if(a < 2)continue;
		while(a > 1)
		{
			v[primes[a]]++;
			a/=primes[a];	
			
		}
	}

}

void newArray(vector<lo>&v, vector<lo>&in)
{
	for(int i = 0; i < in.size(); i++)
	{
		lo a = in[i];
		while(a > 1)
		{
				
			if(v[primes[a]] <= 0)
			{
				in[i]/=primes[a];
			}

			v[primes[a]]--;
			a/=primes[a];
		}

		cout << in[i] << " ";
	}

	cout << endl;
}

void solve()
{
	lo n, m, a; cin >> n >> m; vector<lo>v1(MAX+1), v2(MAX+1), in1, in2;
	
	seive();

	primesPow(n, v1, in1);
	primesPow(m, v2, in2);

	for(int i = 2; i < MAX; i++)
	{
		lo a = min(v1[i], v2[i]);
		v1[i]-=a; v2[i]-=a;

	}

	cout << n << " " << m << endl;

	newArray(v1, in1);

	newArray(v2, in2);

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