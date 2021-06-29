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
		
		lo N, A, B, C, K;

		cin >> N >> A >> B >> C;

		if(A + B - C > N || (A + B - C < 2 && N!=1))
		{
			cout << "IMPOSSIBLE";
			return;
		}

		K = N;

		vector<lo>v;

		A = A - C;
		B = B - C;

		lo a = A, b = B;

		while(C--){
			v.insert(v.begin(),N);
		}

		N--;

		while(A > 0 && N > 0){

			v.insert(v.begin(),N);
			N--;
			A--;

		}

		while(B > 0 && N > 0){

			v.insert(v.end(),N);
			N--;
			B--;

		}

		lo pos1, pos2;

		for(int i = 0;i < v.size(); i++){
			if(v[i] == K){
				pos1 = i;
			}
		}

		for( int i = v.size() - 1; i >= 0; i--){
			if(v[i] == K){
				pos2 = i;
			}
		}

	if(a >= 1 ){
		while(v.size() < K){

			v.insert(v.begin() + pos1, 1);	
			N--;
		}
	}	
	else{

			while(v.size() < K){

			v.insert(v.begin() + pos2 + 1, 1);	
			N--;

		}

	}

	for(int i = 0; i < v.size(); i++){

		cout << v[i] <<" ";

	}

}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);

	freopen("in.txt","r", stdin);

	lo T; cin >> T; lo i = 1;
	while(T--){

		cout << "Case #"<<i<<": ";
		solve();
		i++;
		cout << endl;
	}
	return 0;
}