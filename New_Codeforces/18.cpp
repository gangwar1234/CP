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

vector<string> tokens(string s)
{
	char *temp = strtok((char*)s.c_str(), " ");
	vector<string>v;

	while(temp)
	{
		v.push_back(temp);
		temp = strtok(NULL, " ");
	}

	return v;
}


void solve()
{
	string s; lo n; cin >> n;

	cin.ignore();

	getline(cin, s);

	vector<string>v = tokens(s); stack<lo>st;

	lo i = 0, N = v.size(); vl commas(N,0), braces(N,0);

	if(N == 1)
	{
		if(v[0] == "int")
		{
			cout << v[i]; return;
		}
	}

	while(i < N)
	{
		// cout << " i : " << i << " "<< v[i] << endl;
		if(v[i] == "pair")
		{
			st.push(0); i++;
		}
		else if(v[i] == "int")
		{
			if(st.empty())
			{
				cout << "Error occurred"; return;

			}
			if(st.top() == 0)
			{
				st.pop(); st.push(1);
				commas[i] = 1;
				i++;
			}
			else 
			{
				
				while(st.size() && st.top() != 0)
				{
					st.pop();
					braces[i]++;
				}

				if(st.size())
				{
					st.pop(); st.push(1);
					commas[i] = 1;	
				}
				i++;
			}
		}
	}

	if(st.size())
	{
		cout << "Error occurred"; return;
	}

	string res = "";

	for(int i = 0; i < N; i++)
	{
		if(v[i] == "pair")res += v[i] + "<";
		else
		{
			res += "int";
			
			while(braces[i]--)
			{
				res+=">";
			}
			if(commas[i])res+=",";
		}
	}

	cout << res;
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