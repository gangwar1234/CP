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
	lo N,min_element = INT_MAX, min_idx; cin >> N;

	vector<lo>v(N);

	lo ptr1 = 0, ptr2 = N-1;

	for(int i  = 0; i < N; i++) cin >> v[i];

	sort(v.begin(), v.end());

	for(int i = 1; i < N; i++)
	{
		if(min_element > v[i] - v[i-1])
		{
			min_element = v[i] - v[i-1];
			min_idx = i;
		}
	}

	vector<lo>res(N);

	res[ptr2--] = v[min_idx];

	for(int i = min_idx-2; i >= 0; i--)
	{
		res[ptr2--] = v[i];
	}

	res[ptr1++] = v[min_idx-1];

	for(int i = min_idx+1; i < N; i++)res[ptr1++] = v[i];

	for(int i = 0; i < N; i++)cout << res[i] << " ";

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