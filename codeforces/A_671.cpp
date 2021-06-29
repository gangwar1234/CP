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


void solve(lo T){
		
		lo N;

		cin >> N;

		string s;	

		cin >> s;

		lo L = s.length(), ev_num = 0, od_num = 0;

		REP(0, N)
		{

			if(1 & (i + 1 ))
			{
				if(1 & (s[i] - '0' ))od_num++;
			}

			else
			{
				if(!(1 & (s[i] - '0')))ev_num++;
			}
				
		}

		if(1 & L)
		{
			if(od_num)cout << 1 << endl;
			else cout << 2 << endl;
		}
		else
		{
			if(ev_num) cout << 2 << endl;
			else  cout << 1 << endl;
			
		}
		

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);

	// freopen("in.txt", "r",stdin);

	lo T; cin>>T; lo i = 1;
	while(T--){
	solve(i);
	}
	return 0;
}