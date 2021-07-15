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
	lo n, c, minL = LLONG_MAX, maxR = LLONG_MIN, L, R; cin >> n >> c; 

	unordered_map<lo, lo>mL, mR;

	vector<vector<lo>>v(n, vector<lo>(2));

	for(int i = 0; i < n; i++)
	{
		cin >> L >> R;
		v[i] = {L, R};
		minL = min(minL, L);
		maxR = max(maxR, R);
		mL[L]++;
		mR[R]++;
	}

	debug(maxR);
	debug(minL);

	while(maxR - minL - 1 > c)
	{
		if(mL[minL] == 0)maxR--;
		else if(mR[maxR] == 0)minL++;
		else if(mL[minL] < mR[maxR])minL++;
		else maxR--;
	}

	debug(maxR);
	debug(minL);


	lo res = 0;

	for(int i = 0; i < n; i++)
	{
		res += (min(maxR, v[i][1]) - max(minL, v[i][0]));
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

	lo T, i = 1; cin >>T;

	while(T--)
	{
		cout <<"Case #"<<i<<": ";
		solve();
		i++;
	}

	return 0;

}