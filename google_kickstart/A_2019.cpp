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

bool check(lo x){
	lo count = 0;
	while(x){
		count+=(x%2);
		x=x>>1;
	}

return (1&count);
}

void solve(){
	lo N,Q; cin>>N>>Q;
	vl v(N);
	cin>>v;
	set<int>s;
	REP(0,N){
		if(check(v[i]))s.insert(i);
	}

	while(Q--){
		lo P,A; cin>>P>>A;
		s.erase(P);
		if(check(A)){
			s.insert(P);
		}
		if(s.size()%2==0){
			cout<<N<<" ";
		}
		else{
			lo idx = *s.begin();
			cout<<(N-idx-1)<<" ";
		}
	}	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T,n=1; cin>>T;
	while(T--){
	cout<<"Case #"<<n<<": ";
	solve();
	cout<<endl;
	n++;
	}
	return 0;
}
