#include<bits/stdc++.h>
using namespace std;
#define lo long long int
lo cntB, cntS, cntC, pB, pS, pC, rP, rB = 0, rS = 0, rC = 0;

bool check(lo m)
{

    lo a = max(0LL, rB*m - cntB)*pB;

	lo b = max(0LL, rS*m - cntS)*pS;

	lo c = max(0LL, rC*m - cntC)*pC;

	if(a > rP || b > rP || c > rP || (a + b)> rP || b + c > rP || a + c > rP || a + b + c > rP)return false;

    return true;
}

int main()
{
    string s;

    cin >> s >> cntB >> cntS >> cntC >> pB >> pS >> pC >> rP;
    
    for(auto a : s)
    {
        if(a == 'B')rB++;
        else if(a == 'S')rS++;
        else rC++;
    }
    
    lo l = 0, r = 1e15;
    
    while(l <= r)
    {
		

        lo m = (lo)(l + r)/2;
        
        if(check(m))l = m + 1;
        else r = m - 1;
    }
    
    cout << r << endl;
    
    return 0;
}