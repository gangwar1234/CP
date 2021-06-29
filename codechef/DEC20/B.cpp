#include<bits/stdc++.h>
using namespace std;
#define lo long long int
class MedianFinder {
public:

    priority_queue<int>p_max;
    
    priority_queue<int, vector<int>, greater<int>>p_min;
    
    MedianFinder() {
        
        p_max = priority_queue<int>();
        
        p_min = priority_queue<int, vector<int>, greater<int>>();
        
    }
    
    void addNum(int num) {
        
      p_max.push(num);
        
      p_min.push(p_max.top());
        
      p_max.pop();
      
      if(p_max.size() < p_min.size())
      {
          p_max.push(p_min.top());
          
          p_min.pop();
      }
        
    }
    
    pair<int, int> findMedian() {
        
        int n = p_max.size() , m =  p_min.size();
        
        if( (n + m ) % 2 == 0)
        {
            return {p_max.top(), p_min.top()};

        }
        else if(p_max.size() < p_min.size()){
            
            return {p_min.top(), 1};
        
        }
        else{
            return {p_max.top(),1};
        }
        return {0,0};
    }
};


void solve()
{
    lo N, Q;

    cin >> N >> Q;

    vector<lo>v(N);

    for(int i =- 0; i < N; i++)cin >> v[i];

    vector<vector<int>>MIN(N*N), MAX(N*N);

    vector<vector<pair<int, int>>>MED(N*N);

    for(int l = 0; l < N; l++)
    {
        lo min_val = v[l], max_val = v[l];

        for(int r = l; r < N; r++)
        {
            MIN[l][r] = min(min_val, v[r]);
            MAX[l][r] = max(max_val, v[r]);
            min_val = MIN[l][r];
            max_val = MAX[l][r];
        }
    }

    for(int l = 0; l < N; l++)
    {
        MedianFinder* obj = new MedianFinder();
        for(int r = l; r < N; r++)
        {
            obj->addNum(v[r]);

            MED[l][r] = obj->findMedian();
            
        }   

        delete obj;
    }

    while(Q--)
    {

        lo L, R;

        cin >> L >> R;

        auto mid = MED[L][R];
        lo min_e = MIN[L][R];
        lo max_e = MAX[L][R];

        pair<int, int> x = {min_e*mid.second - mid.first, mid.second};

        pair<int, int> y = {max_e*mid.second - mid.first, mid.second};

        pair<int, int>A = {x.first*y.second, x.second*y.first};

        lo g = __gcd(A.first, A.second);


        if(A.second/g == 0)cout <<"undefined"<<endl;
        else
        cout << A.first/g << "/"<<A.second/g << endl;

    }
    
}

int main()
{
    lo T;

    cin >> T;

    while(T--)
    {
        solve();
    }

    return 0;
}
