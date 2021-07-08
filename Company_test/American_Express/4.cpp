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


int LongestPalindromicPrefix(string str) 
{ 
  
    // Create temporary string 
    string temp = str + '?'; 
  
    // Reverse the string str 
    reverse(str.begin(), str.end()); 
  
    // Append string str to temp 
    temp += str; 
  
    // Find the length of string temp 
    int n = temp.length(); 
  
    // lps[] array for string temp 
    int lps[n]; 
  
    // Intialise every value with zero 
    fill(lps, lps + n, 0); 
  
    // Iterate the string temp 
    for (int i = 1; i < n; i++) { 
  
        // Length of longest prefix 
        // till less than i 
        int len = lps[i - 1]; 
  
        // Calculate length for i+1 
        while (len > 0 
               && temp[len] != temp[i]) { 
            len = lps[len - 1]; 
        } 
  
        // If character at current index 
        // len are same then increament 
        // length by 1 
        if (temp[i] == temp[len]) { 
            len++; 
        } 
  
        // Update the length at current 
        // index to len 
        lps[i] = len; 
    } 
  
    // Print the palindromic string of 
    // max_len 
    string ans = temp.substr(0, lps[n - 1]);

	return ans.length();
} 
  

void solve(lo T){
  

    string str = "abaab"; 

	int l = str.length();

	while(l > 1)
	{

   		int r =  LongestPalindromicPrefix(str); 

		str = str.substr(r-1); 

		l = str.length();

	}

	cout << str << endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	lo T; T = 1; lo i = 1;
	solve(T);
	return 0;
}