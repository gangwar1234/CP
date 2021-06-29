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

void do_find(int i,int &l,int &r, vector<lo>&wheel, int n)
{

    while(l < i && wheel[i] - wheel[l] >  n - wheel[i] + wheel[l]) l++;
    
    while(r > i && wheel[r] - wheel[i] >  n + wheel[i] - wheel[r]) r--;
}

lo solve()
{
        lo w,n;

        cin >> w >> n;

        vector < lo > wheel(w), Pre(w+1);

        cin >> wheel;

        sort(all(wheel));
        
        for(int i = 0; i < w; i++)Pre[i+1] = Pre[i] + wheel[i];

        int l = 0, r = w - 1, res = INT_MAX;
        
        for(int i = 0; i < w; i++)
        {

            // cout <<" ********************************"<<endl;

            do_find(i,l,r, wheel, n);

            // debug(l);
            // debug(r);
            // debug(w);

            int x = (i-l+1)*wheel[i] - (Pre[i+1] - Pre[l]);
            
            int y = l*(n-wheel[i]) + Pre[l];
            
            int z = -(r-i+1)*wheel[i] + (Pre[r+1] - Pre[i]);
            
            int m = (w-r-1)*(n+wheel[i]) - (Pre[w]-Pre[r+1]);
            
            res = min(res, x+y+m+z);

        }

    return res;
}

int main() {

    lo test;

    freopen("in.txt", "r", stdin);
    
    cin>>test;
    
    lo t = 1;
    
    while(test--){

        lo res = solve();

        cout << "Case #" << t << ": "<< res << "\n";
        
        t++;
        
    }
	// your code goes here
	return 0;
}