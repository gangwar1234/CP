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


bool check(int row,int col,vector<vector<lo>>&v){
	for(int i=0;i<v[0].size();i++){
		if(v[row][i]==1)return false;
	}
	for(int i=0;i<v.size();i++){
		if(v[i][col]==1)return false;
	}
	return true;
}

void solve(){
	lo N,M;
	cin>>N>>M;
	vector<vector<lo>>v(N,vector<lo>(M,0));
	bool flag = false;
	REPV(j,0,N){
		REPV(k,0,M)cin>>v[j][k];
	}



	lo i=0;
	while(1){
		flag = false;
		for(lo j=0;j<N;j++){
			for(lo k=0;k<M;k++){
				
				if(v[j][k]==0&&check(j,k,v)){
					v[j][k] = 1;
					flag = true;
					}
			}
			if(flag)break;
		}
		if(!flag){
			if(i%2==0)cout<<"Vivek"<<endl;
			else
			{
				cout<<"Ashish"<<endl;
			}
			break;
			
		}
	
		i++;	
	}	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T;
	cin>>T;
	while(T--){
	solve();
	}
	return 0;
}