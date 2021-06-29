#include <bits/stdc++.h>
using namespace std;
#define lo long long int

vector<string> split_string(string);

lo merge(vector<lo>&arr,lo l,lo m, lo r){

    vector<lo>L(m-l+2),R(r-m+1);
    lo N1 = m - l + 1, N2 = r - m;
    for(int i=l,j=0;j<N1;i++,j++)L[j] = arr[i];
    for(int i=m+1, j=0;j<N2;i++,j++)R[j] = arr[i];
    L[m-l+1] = LLONG_MAX;
    R[r-m] = LLONG_MAX;
    lo k = l, i = 0, j = 0;
    lo inv = 0;

    while(k<=r){
        if(L[i]<=R[j])arr[k++] = L[i++];
        else 
        {
            arr[k++] = R[j++];
            if(L[i]!=LLONG_MAX)
            inv+=(N1-i); 
        }
    }



    return inv;
}


lo merge_sort(vector<lo>&arr, lo l,lo r){
    
    lo inversion = 0;
    if(l<r){
    lo mid = (l+r)>>1;
    inversion+=merge_sort(arr, l, mid);
    inversion+=merge_sort(arr,mid+1,r);
    inversion+=merge(arr,l,mid,r);
    }
    return inversion;
}


// Complete the countInversions function below.
long countInversions(vector<lo> arr) {
    vector<lo>temp = arr;

    int ans = (merge_sort(temp,0,arr.size()-1));
return ans;

}

int main()
{
    lo T;
    freopen("in.txt","r",stdin);
    cin>>T;
    while(T--){
        lo n;
        cin>>n;
        vector<lo>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        cout<<countInversions(v)<<endl;
    }   
    return 0;
}
