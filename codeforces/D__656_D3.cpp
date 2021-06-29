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


lo recur(vll &freq,int left,int right,int search){

	if(left>right)return INT_MAX;
	lo m = (left + right)>>1;
	lo x = freq[m][search] - ((left==0)?0:(freq[left-1][search]));
	lo y = freq[right][search] - freq[m][search];
		if(left==right){
		if(x==1||y==1)return 0;
		return 1;
	}
	lo n = right - left + 1;
	lo lx = (n>>1)-x;
	lo rx = (n>>1) -y; 
	lo l = recur(freq,left,m,search+1);
	lo r = recur(freq,m+1,right,search+1);
	return min(lx+r,rx+l);
}

void solve(){
		string s;
		lo n; cin>>n;
		cin>>s;
		vll freq(s.length(),vl(26,0));
		for(int i=0;i<s.length();i++)
		{
			for(int j = 0;j<26;j++){
				if(j==s[i]-97)freq[i][j]=((i==0)?0:freq[i-1][j])+1;
				else freq[i][j]=(i==0)?0:freq[i-1][j];
			}
		}


		lo left = 0, right = s.length() - 1,search =0;

		lo ans = recur(freq,left,right,search);
		cout<<(ans)<<endl;
		return;
		
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T;
	while(T--){
	solve();
	}
	return 0;
}