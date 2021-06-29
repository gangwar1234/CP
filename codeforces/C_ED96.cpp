#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) 


template <typename T>

istream &operator>>(istream &in, vector<T> &v)
{
	for (unsigned i = 0; i < v.size(); i++)
		in >> v[i];
	return in;
}
int x[4] = {0,-1, 0,  1};
int y[4] = {1, 0, -1, 0};

bool valid(int i, int j, int N, int M)
{
    if(i >= N || j >= M || i < 0 || j < 0)return false;
    
    return true;
}

bool check(vector<vector<int>>&mat, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                int xx = i + x[k];
                int yy = j + y[k];
                if(valid(xx, yy, N, N) && abs(mat[xx][yy]-mat[i][j])<= 1)return false;
            }
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)cout << mat[i][j] << " ";
        cout << endl;
    }

	return true;
}

void fill(int N, vector<vector<int>>&mat)
{
    lo p1 = 0, p2 = N - 1, i = 0, cnt = 1;
    
    while(p1 < N && p2 >= 0)
    {

        if(i%2==0)
        {
            for(int row = 0, col = p1; col >= 0; row++, col--)
            mat[row][col] = cnt++;
            
            p1++;
        }
        else
        {
             for(int row = p2, col = N-1; row < N; row++, col--)
                mat[row][col] = cnt++; 
                p2--;
        }
        
        i++;
    }
    
 
}


void solve()
{
    lo N;
    
    cin >> N;
    
    vector<vector<int>>mat(N, vector<int>(N));
    
    fill(N, mat);
    
    if(!check(mat, N))cout << -1 << endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; cin>>T; int i = 0;
	while(T--){
	solve();
	}
	return 0;
}