#define mod 1000000007
#define lo long long int
int gcd(int a,int b){
    if(a==0)return b;
    return gcd(b%a,a);
}


int KMP(string s){
    vector<int>pi(s.length(),0);
    for(int i=1;i<s.length();i++){
        int j = pi[i-1];
        while(j>0&&s[i]==s[j])j = pi[j-1];
        if(s[i]==s[j])j++;
        pi[i] =  j;
    }
    
    return pi[s.length()-1];
}

bool check(string s,int n){
    for(int i=0;i+n<=s.length();i+=n){
        if(s.substr(i,n)!=s)return false;
    }
    return true;
}

int Solution::solve(vector<string> &A) {

    vector<int>ans;
    for(int i=0;i<A.size();i++){
        string s = A[i];
        int n1 = s.length(),n2 = KMP(s),n;
        if(check(s,n2))n = n2;
        else n = n1;
        int x = 1;
        while((x*(x+1)/2)%n!=0)x++;
        ans.push_back(x);
    }
    lo val = ans[0],final = 1;
    for(int i=0;i<ans.size()-1;i++){
        val = gcd(ans[i],ans[i+1]);
        final = ((ans[i+1]*ans[i])/val)%mod;
        
    }
    return final;
}
