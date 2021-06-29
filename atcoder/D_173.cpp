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
	lo ans = 0;
		lo N; cin>>N;
		vl v(N); cin>>v;
		sort(v.begin(),v.end(),greater<lo>());
		int i=0;
		priority_queue<int>q;q.push(0);
		while(i<N){
			lo a = q.top();q.pop();
			ans+=a;
			q.push(v[i]);
			if(i!=0){
				q.push(v[i]);
			}
			i++;
		}

		cout<<ans<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	solve();
	return 0;
}
