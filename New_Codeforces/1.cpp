#include <bits/stdc++.h>
using namespace std;
#define lo long long int 
#define MOD 1000000007



int main() 
{
	
  lo N, sum = 0, length = 1;
  
  cin >> N;
  
  vector<lo>arr(N+3), arr1(N+3);
  
  while(N--)
  {
      lo T, x, a;
      
      cin >> T;
      
      if(T==1)
      {
          cin >> a >> x;
          
          sum += (x*min(a, length));
          
          arr1[min(a, length)] += x;
          
          
      }
      else if(T == 2)
      {
          cin >> a;
          
          arr[++length] = a;
          
          sum += a;
      }
      else
      {
        //   for(auto u : arr)cout << u << " ";
        //   cout << endl;
          
        //   for(auto v : arr1)cout << v << " ";
          
        //   cout << endl;
          
        //   cout << " prev sum : " << sum << endl;
          sum -= (arr[length] + arr1[length]);
        //   cout << " new sum : " << sum << endl;
          arr1[length-1] += arr1[length];
          arr[length] = 0;
          arr1[length] = 0;
          length--;
      }
      
      cout<< fixed << setprecision(6) << (double)sum/length << endl;
  }
  
  return 0;
}
