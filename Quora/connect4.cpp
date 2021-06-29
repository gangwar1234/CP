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

lo ofset = 4;

lo fillCol(lo col, vector<string>&v, lo chance)
{
	for(int i = ofset; i < 14; i++)
	{
		if(v[i][col] == '*'){v[i][col] = (chance==0)?('R'):('Y');return i;}
	}

	return 14;

}


bool Check(lo row, lo col, vector<string>&v, char chance)
{
	// vertical

	// debug(chance);
	lo cnt = 0;
	for(int i = row; i < row+4; i++)if(v[i][col]==chance)cnt++;
	if(cnt == 4)return true;	cnt = 0;
	for(int i = row; i < row-4; i--)if(v[i][col]==chance)cnt++;
	if(cnt == 4)return true;	cnt = 0;

	//horizontal

	for(int i = col; i < col+4; i++)if(v[row][i]==chance)cnt++;
	if(cnt == 4)return true;	cnt = 0;
	for(int i = col; i > col-4; i--)
		{
			// debug(v[row][i])
			if(v[row][i]==chance)cnt++;
		}
	// debug(cnt);
	if(cnt == 4)return true;	cnt = 0;

	// Diagonal
	for(int i = row, j = col; i < row+4 && j < col+4; i++, j++)if(v[i][j]==chance)cnt++;
	if(cnt == 4)return true;	cnt = 0;
	for(int i = row, j = col; i > row-4 && j > col-4; i--, j--)if(v[i][j]==chance)cnt++;
	if(cnt == 4)return true;	cnt = 0;

	for(int i = row, j = col; i < row+4 && j > col-4; i++, j--)if(v[i][j]==chance)cnt++;
	if(cnt == 4)return true;	cnt = 0;
	for(int i = row, j = col; i > row-4 && j < col+4; i--, j++)if(v[i][j]==chance)cnt++;
	if(cnt == 4)return true;	cnt = 0;
	
	return false;
}

void solve(){

	vector<string>v(14, "***************");
	lo T = 42,  col, chance = 0;
	
	// for(auto s : v)cout << s << endl;

	while(T--)
	{
		cin >> col;
		// debug(col);
		col+=3;
		lo row = fillCol(col, v, chance%2);

		// debug(row);
		// debug(col);
		// debug(chance+1);

		// for(auto s : v)cout << s << endl;

		char P = (chance%2==0)?('R'):('Y');
		// debug(P);

		for(int i = 0; i < 14; i++){

			for(int j = 0; j < 15; j++){	

			if(v[i][j]=='*')continue;
			if(Check(i, j,v ,v[i][j]))
			{
				if(v[i][j] == 'R')
				{
					cout << "RED" << " " << (chance+1) <<endl;
				}
				else
				{
					cout << "YELLOW" << " " << (chance+1)<<endl;
				}
				return;
			}
			}
		}
		chance++;
	}

	cout << "DRAW"<<endl;
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