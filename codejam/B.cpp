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


void solve(){
		
		lo X, Y, cost = 0;

		string S, P = "";

		cin >> X >> Y >> S;

		for(int i = 0; i < S.length(); i++)
		{
			if(S[i] == '?')continue;
			 P+=S[i];
		}
		// cout<<"P is "<<(P.length()-1)<<endl;

		if(P.length()!=0){
			for(int i = 0; i < (P.length()-1); i++)
			{
				// cout<<"in loop "<<P<<" "<<i<<endl;
				if(P[i] == 'C' && P[i+1] == 'J')cost += X;
				else if(P[i] == 'J' && P[i+1] == 'C')cost += Y;
			}
		}

		
		// cout<<"here"<<endl;
		cout << cost << endl;
		
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T, i = 1;

	cin >> T;

	while(T--)
	{
		cout << "Case #"<<i<<": ";
		solve();
		i++;
	
	}
	return 0;
}