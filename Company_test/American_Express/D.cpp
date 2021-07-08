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

string sum(string s)
{
    cout << "S : " << s << endl;


    int count = 0;


    for(int i  = 0; i < s.length(); i++)
    {
        count+= (s[i] - '0');
    }

    return to_string(count);
}

void solve()
{

    string s = "0";
    
    string temp = "";

    int k = 100;

    while(s.length() > k)
    {
         temp = "";

        for(int i = 0; i < s.length(); i+=k)
        {
            temp += sum(s.substr(i,k));
        }

        s = temp;
    }

    cout << temp << endl;
  
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; T = 1; lo i = 1;
	solve();
	return 0;
}