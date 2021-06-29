#include<bits/stdc++.h>
using namespace std;
#define lo long long int


int main() {
    
    lo T, N, Q, a;
    
    cin >> T;
    
    while(T--)
    {
        
        list<lo>s;
        unordered_map<lo, list<lo>::iterator>m;
        
        cin >> N >> Q;
        
        for(int i = 0; i < N; i++)
        {
            cin >> a;
            
            s.insert(s.end(), a);
            
            if(m.find(a) == m.end()) m[a] = s.end();

        }
        
        
        for(int i = 0; i < Q; i++)
        {
            cin >> a;
            
            cout<<(m[a] - s.begin()) << endl;
            
            s.erase(m[a]);
            
            s.insert(s.begin(), a);
            
            m[a] = s.begin();
            
            
        }
    }
    

	return 0;
}
