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



lo solution(vl &E, vl &R){

		lo sum = accumulate(E.begin(), E.end(),0);
		lo x = sum;
		if(E.size()==1)return sum;
		for(int i = 0; i < E.size();i ++){
			if(x - R[i] - E[i] >=0){
				sum+=E[i];
			}
			else{
				return sum;
			}

		}

		

	return -1;
}



void find_Comb(vector<lo>&E, vector<lo>&R){

	lo N = E.size();

	lo count =  0, ans = INT_MIN, temp = 0; 

	for(int i = 0; i < (1<<N) ; i++){

			vector<lo>v, s;

			for(int j = 0; j < N; j ++){

					if(i&(1<<j)){
							v.push_back(E[j]);
							s.push_back(R[j]);
					}

			}
		if(v.size() == 0)continue;	
		temp = solution(v,s);	
		if(temp == -1){
			count = N - v.size();
			cout << count <<" INDEFINITELY";
			return;

		}
		if(ans < temp){
			count = N - v.size();
			ans = temp;
		}

	}
	cout << count <<" "<< ans;

}



void solve(){

	lo N;
	
	cin >> N;

	vl E(N), R(N);

	REP(0,N){

		cin >> E[i] >> R[i];

	}

	vector<vector<lo>>V_E, V_R;

	find_Comb(E, R);

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	freopen("in.txt","r",stdin);
	lo T; cin >> T; lo i = 1;
	while(T--){

		cout <<"Case #"<<i<<": ";

		solve();
		i++;

		cout << endl;
	}
	return 0;
}