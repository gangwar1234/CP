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
		

		lo N, K, max_e = INT_MIN, min_e = INT_MAX;
		
		cin >> N >> K;

		priority_queue<lo>p;

		REP(0, N)
		{
			lo a;

			cin >> a;
			max_e = max(max_e, a);
			min_e = min(min_e, a);

			p.push(a);
		}

		if(K == 0)
		{
			cout << (max_e - min_e) << endl;
			return;
		}
		while(K--)
		{
			lo a = p.top(); p.pop();
			lo b = p.top(); p.pop();

			p.push(a + b);
		}

		cout << p.top() << endl;

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