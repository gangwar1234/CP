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
	
	lo n, k;  cin >> n >> k;

	vector<string>v, str(4*n);

	for(int i = 0; i < 4*n; i++)cin >> str[i];

	for(int i = 0; i < 4*n; i++){
		
		string s = str[i];

		lo len = s.length(), cnt = 0;
		
		for(int j = len-1; j >= 0; j--){
			if(s[j] == 'a' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'e'){
				cnt++;

				if(cnt == k){
					v.push_back(s.substr(j));
					break;
				}
			}
		}

		if(cnt != k){
			cout << "NO" << endl;
			return;
		}
	}

	vector<string>res;

	// for(int i = 0; i < v.size(); i++)cout<< " val : " << v[i] << endl;

	for(int i = 0; i < v.size(); i+=4){

		if(v[i] == v[i+1] && v[i+1] == v[i+2] && v[i+2] == v[i+3])res.push_back("aaaa");
		else if(v[i] == v[i+1] && v[i+2] == v[i+3]) res.push_back("aabb");
		else if(v[i] == v[i+2] && v[i+1] == v[i+3]) res.push_back("abab");
		else if(v[i] == v[i+3] && v[i+1] == v[i+2]) res.push_back("abba");
		else {
			cout << "NO" << endl;
			return; 
		}

	}

	for(int i = 1; i < res.size(); i++){
		
		if(res[i] == "aaaa") res[i] = res[i-1];

		if(res[i-1] == "aaaa") res[i-1] = res[i];

		if(res[i]!= res[i-1])
		{
			cout << "NO" << endl; return;
		}
	}

	cout << res[0] << endl;
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