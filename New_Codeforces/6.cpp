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
	lo n, l = 0; cin >> n;	char ch;

	string s, w, res; unordered_map<string, bool>m;

	REP(0, n){
		cin >> s;
		transform(s.begin(), s.end(), s.begin(),::tolower);
		m[s]=true;
	}

	cin >> w >> ch; 

	char chLower = tolower(ch);
	char chUpper = toupper(ch);

	for(int i = 0; i < w.length(); i++){
		lo  r = -1; 
		for(int j = i; j < w.length(); j++){

			s = w.substr(i, j-i+1);

			transform(s.begin(), s.end(), s.begin(),::tolower);

			if(m[s])r = max(r, (lo)j);
		}

		if(l <= r){

			for(int j = l; j <= r; j++){


				if(w[j] >= 'a' && w[j] <= 'z'){

						if(chLower == w[j]){
							for(int k = 0; k < 26; k++){
								if('a'+k!= chLower){
									res += (char)('a'+k);
									break;
								}
							}
						}else res += chLower;
					}
					else{
						if(chUpper == w[j]){
							for(int k = 0; k < 26; k++){
								if('A'+k!= chUpper){
									res += (char)('A'+k);
									break;
								}
							}
						}else res += chUpper;						
					}
				
			}
			l = r+1;
		}
		else if(l == i){res+=w[i];l++;}
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

	lo T; T=1;

	while(T--)
	{
		solve();
	}

	return 0;

}