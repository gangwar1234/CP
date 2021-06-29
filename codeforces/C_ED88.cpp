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





lo getMid(lo s, lo e)  
{ 
    return s + (e - s) / 2; 
} 
  
/*  A recursive function to get the sum of 
    values in given range of the array.  
    The following are parameters for this 
    function. 
  
    st       -> Pointer to segment tree 
    node     -> Index of current node in  
                the segment tree . 
    ss & se  -> Starting and ending indexes  
                of the segment represented 
                by current node, i.e., st[node] 
    l & r    -> Starting and ending indexes  
                of range query */
lo MaxUtil(lo* st, lo ss, lo se, lo l,  
            lo r, lo node) 
{ 
    // If segment of this node is completely 
    // part of given range, then return  
    // the max of segment 
    if (l <= ss && r >= se) 
        return st[node]; 
  
    // If segment of this node does not 
    // belong to given range 
    if (se < l || ss > r) 
        return -1; 
  
    // If segment of this node is partially 
    // the part of given range 
    int mid = getMid(ss, se); 
      
    return max(MaxUtil(st, ss, mid, l, r,  
                       2 * node + 1), 
               MaxUtil(st, mid + 1, se, l,  
                       r, 2 * node + 2)); 
} 
  

int getMax(lo* st, lo n, lo l, lo r) 
{ 
    // Check for erroneous input values 
	debug(l); debug(r); debug(n);
    if (l < 0 || r > n - 1 || l > r)  
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return MaxUtil(st, 0, n - 1, l, r, 0); 
} 
  
// A recursive function that constructs Segment 
// Tree for array[ss..se]. si is index of  
// current node in segment tree st 
lo constructSTUtil(lo arr[], lo ss, lo se,  
                    lo* st, lo si) 
{ 
    // If there is one element in array, store 
    // it in current node of segment tree and return 
    if (ss == se)  
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
  
    // If there are more than one elements, then 
    // recur for left and right subtrees and  
    // store the max of values in this node 
    lo mid = getMid(ss, se); 
      
    st[si] = max(constructSTUtil(arr, ss, mid, st,  
                                 si * 2 + 1), 
                 constructSTUtil(arr, mid + 1, se,  
                                 st, si * 2 + 2)); 
      
    return st[si]; 
} 
  
/* Function to construct segment tree from given array. 
   This function allocates memory for segment tree.*/
lo* constructST(lo arr[], lo n) 
{ 
    // Height of segment tree 
    lo x = (int)(ceil(log2(n))); 
  
    // Maximum size of segment tree 
    lo max_size = 2 * (lo)pow(2, x) - 1; 
  
    // Allocate memory 
    lo* st = new lo[max_size]; 
  
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n - 1, st, 0); 
  
    // Return the constructed segment tree 
    return st; 
} 


void solve(){

lo n;
cin>>n;
lo arr[n+1];
REP(0,n)cin>>arr[i];
lo* st = constructST(arr, n);
lo ans = arr[0], ans_l = 0, ans_r = 0;
lo sum = 0, minus_pos = -1;
if(n==1){cout<<"0"<<endl;return;}
for (lo r = 0; r < n; ++r) {
    sum += arr[r];
    if (sum - getMax(st, n, minus_pos+1, r) > ans) {
        ans = sum - getMax(st, n, minus_pos+1, r);
        ans_l = minus_pos + 1;
        ans_r = r;
    }
    if (sum < 0) {
        sum = 0;
        minus_pos = r;
    }
	
}

cout<<ans<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
	solve();
	return 0;
}