#include <bits/stdc++.h>
using namespace std;
typedef  long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) 
#define REP(a,b) for(lo i =(a) ;i<(b);i++)
#define mod 1000000007





void solve(lo T){
	
	lo N,K,W;
	cin>>N>>K>>W;
	vl L(N);
	REP(0,K)cin>>L[i];
	lo A_l, B_l, C_l,D_l;
	cin>>A_l>>B_l>>C_l>>D_l;
	vl H(N);
	REP(0,K)cin>>H[i];

	lo A_h, B_h, C_h, D_h;
	cin>>A_h>>B_h>>C_h>>D_h;

	for(int i = K;i<N;i++){

		L[i] = ((((A_l*L[i-2])%D_l) + ((B_l*L[i-1])%D_l) + C_l)%D_l) + 1;
		H[i] = ((((A_h*H[i-2])%D_h) + ((B_h*H[i-1])%mod) + C_h)%D_h) + 1;
	
	}



	vector<lo>P(N);

	vector<lo>L_h(N), R_h(N);
	lo ans = 1;

	lo h = INT_MIN;

	lo F_l = L[0], S_l = L[0] + W, Previous = -W, peri = 0;  
	vl pos(W,0);

	for(int i = 0;i<N;i++){
		lo idx = Previous;
		F_l = idx - i;
		lo cur = L[i] - idx;
		S_l = cur;
		vl tmp;
		lo sz = 0;
		for(int j = cur-1;j<W;j++){
			vector<lo>L_h(N), R_h(N);
			sz = max(sz,pos[j]);
			F_l = sz - 2*h;
			if(j!=cur-1)tmp.push_back(max(H[i],pos[j]));
			S_l = F_l + W;
		}
		lo t = tmp.size();
		vector<lo>L_h(N), R_h(N);
		peri+=2*max(0LL,H[i] - sz);
		vector<lo>P(N);
		peri%=mod;
		h = F_l - S_l;
		for(int j=0;j<W-t;j++){
			h = peri*2;
			peri+=2;
			F_l = peri;
			peri%=mod;
			S_l = peri;
			tmp.push_back(H[i]);
		}
		pos = tmp;
		peri%=mod;
		F_l = peri*2;
		ans = (ans*peri)%mod;
		S_l = ans - 1;
		Previous = L[i];

}

	cout<<ans<<endl;


}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	freopen("in.txt","r",stdin);
	lo T; cin>>T; lo i = 1;
	while(T--){
	cout<<"Case #"<<i<<": ";	
	solve(i);
	i++;
	}
	return 0;
}