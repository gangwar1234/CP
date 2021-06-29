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
#define PI 3.14159265
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

lo tanCal(lo x1, lo y1, lo x2, lo y2)
{
	return (atan2(y2-y1, x2-x1)*180/PI);
}

void solve()
{
	map<pair<lo, lo>, bool>m;	
	lo x1, y1, x2, y2, max_x = INT_MIN, min_x = INT_MAX, max_y = INT_MIN, min_y = INT_MAX;
	vector<vector<lo>>pairs;

	for(int i = 0; i < 8; i++)
	{
		cin >> x1 >> y1;

		max_x = max(max_x, x1);
		max_y = max(max_y, y1);

		min_x = min(min_x, x1);
		min_y = min(min_y, y1);

		if(m.find({x1, y1}) == m.end())
		{
			pairs.push_back({x1,y1});
			m[{x1,y1}] = true;
		}

	}

	if(pairs.size()!= 4)
	{
		cout << "NO"; return;
	}

	if(min_x == max_x || min_y == max_y)
	{
		cout << "NO" << endl; return;
	}

	// cout << max_x << " " << max_y << " " << min_x << " " << min_y << endl;

	if(m.find({max_x, max_y})== m.end()){cout << "NO"; return;}
	if(m.find({max_x, min_y})== m.end()){cout << "NO"; return;}
	if(m.find({min_x, max_y})== m.end()){cout << "NO"; return;}
	if(m.find({min_x, min_y})== m.end()){cout << "NO"; return;}

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

	lo T; T = 1;

	while(T--)
	{
		solve();
	}

	return 0;

}