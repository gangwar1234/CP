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



string dp_solve(vector<lo>&temp ,lo sum){
	vector<vector<lo>>dp(temp.size()+1,vector<lo>(sum+1,false));
	for(int i=0;i<=temp.size();i++)dp[i][0] = true;

	REPV(i,1,temp.size()+1){
		REPV(j,1,sum+1){
			if(j>=temp[i-1])
			dp[i][j] = (dp[i-1][j-temp[i-1]]|dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	if(dp[temp.size()][sum])return "YES";
	return "NO";
}

void solve(int T){
		lo N; cin>>N; vl v(2*N); cin>>v; lo last  = 2*N;
		vl temp;
		while(last > 0){
			lo idx  = max_element(v.begin(),v.begin()+last) -  v.begin();
			temp.push_back(last-idx);
			last = idx;
			
		}
		cout<<dp_solve(temp,N)<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T; int i = 1;
	while(T--){
	solve(i);
	 i++;
	}
	return 0;
}