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

string split(string s)
{
	string res = "";	
	char *temp = (char*)strtok((char*)s.c_str()," ");
	unordered_map<string, string>m;
	m["lios"]="a"; m["liala"]="A";
	m["etr"]="n"; m["etra"]="N";
	m["initis"]="v"; m["inites"]="V";

	while(temp)
	{

		string p = temp, r; bool flag = false;

		if(p.length() >= 6)
		{
			r =  p.substr(p.length()-6);
			if(m.find(r) != m.end())
			{
				res+=m[r];
				flag = true;
			}
		}

		if(p.length() >= 5 && !flag)
		{
			r =  p.substr(p.length()-5);
			if(m.find(r) != m.end())
			{
				res+=m[r];
				flag = true;
			}				
		}
		
		if(p.length() >= 4 && !flag)
		{
			r =  p.substr(p.length()-4);
			if(m.find(r) != m.end())
			{
				res+=m[r];
				flag = true;
			}			
		}
		
		if(p.length() >= 3 && !flag)
		{
			r =  p.substr(p.length()-3);
			if(m.find(r) != m.end())
			{
				res+=m[r];
				flag = true;
			}	
		}

		if(!flag)res+="k";
		temp = strtok(NULL, " ");
	}

	return res;
}

void solve()
{
	string s, p="";  getline(cin, s);

	lo lLimit, rLimit; s+=" ";
	string res = split(s);

	if(res[0] >= 'a' && res[0] <= 'z')
	{
		lLimit = 'a'; rLimit = 'z'; 
	}
	else
	{
		lLimit = 'A'; rLimit = 'Z';
	}

	p += res[0];

	for(int i = 1; i < res.length(); i++)
	{	
		if(res[i] < lLimit || res[i] > rLimit)
		{
			cout << "NO"; return;
		}
		if(res[i]!= res[i-1])p+=res[i];
	}

	if(p == "ANV" || p == "NV" || p == "AN" || p == "N" || p == "anv" || p == "nv" || p == "an" || p == "n")cout << "YES";
	else
	cout << "NO";
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