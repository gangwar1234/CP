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

	vl v(N);

	cin >> v;

	lo sum = 0;

	lo sum1 = accumulate(v.begin(), v.end(), 0);

	if(sum1 == 0)
	{
		cout << "NO" << endl;
		return;
	}

	lo pos = 0, neg = 0, zero = 0;

	for(auto a : v)
	{
		if(a > 0) pos += a;

		else if(a < 0) neg += a;

		else zero++;
	}

	if(pos > abs(neg))
	{
		sort(v.begin(), v.end(), greater<lo>());
	}
	else{
		sort(v.begin(), v.end());
	}

	cout << "YES" << endl;

	for(auto a : v)cout << a <<" ";

	cout << endl;

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