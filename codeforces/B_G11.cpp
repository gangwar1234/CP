#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
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


int compute(string s)
{
	int count = 0;

	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == 'W')count++;

		if(i > 0&& s[i] == 'W' && s[i-1] == 'W')count++;

	}

	return count;
}


void solve(lo T){
		
		lo N, K; string s;
		
		cin >> N >> K >> s;

		vector<int>middle;

		int corner = 0, ans = compute(s);

		if(ans == 0)
		{
			ans = (N > K) ? (2 * K - 1) : (2 * N - 1);

			cout << max(ans, 0) << endl;

			return;
		}

		for(int i = 0; i < N;)
		{
			if(s[i] == 'W')
			{
				i++;	continue;
			}

			bool start_l = (i == 0);

			int count = 0;

			while(i < N && s[i] == 'L')i++, count++; 

			bool end_l = (i == N);

			if(start_l || end_l) corner += count;
			else middle.push_back(count);


		}

		sort(all(middle));

		for(auto x : middle)
		{

			while(x && K)
			{
				if(x == 1)ans += 3;
				else ans+=2;
				K--; x--;
			}
		}

		while(corner && K)
		{
			ans+=2;
			K--; corner--;
		}

		cout << ans << endl;
		
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);

	// freopen("in.txt", "r", stdin);
	lo T; cin>>T; lo i = 1;
	while(T--){
	solve(i);
	}
	return 0;
}