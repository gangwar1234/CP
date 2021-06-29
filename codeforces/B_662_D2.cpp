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
		lo N; cin>>N;
		vl v(N); cin>>v;
		lo q; cin>>q;

		lo four = 0, two = 0; 

		map<lo,lo>m;

		REP(0,N)m[v[i]]++;
		
		for(auto a:m){
			lo x = a.second/4;
			lo y = a.second%4;
			lo z = y/2;
			four+=x;
			two+=z;
		}



		while(q--){
			char c; cin>>c;	
			lo x; cin>>x;
			if(c=='+'){

				lo r = m[x];
				lo s = r/4;
				lo t = r%4;
				lo u =  t/2;

				four-=s;
				two-=u;
				m[x]++;

				 r = m[x];
				 s = r/4;
				 t = r%4;
				 u =  t/2;
				four+=s;
				two+=u;				 

			}
			else{

				lo r = m[x];
				lo s = r/4;
				lo t = r%4;
				lo u =  t/2;
				four-=s;
				two-=u;
				m[x]--;

				 r = m[x];
				 s = r/4;
				 t = r%4;
				 u =  t/2;
				four+=s;
				two+=u;				

			}



			if(four>1)cout<<"YES"<<endl;
			else{

				if(four==1&&two>1)cout<<"YES"<<endl;
				else cout<<"NO"<<endl;

			}

		}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	// freopen("in.txt","r",stdin);
	solve();
	return 0;
}