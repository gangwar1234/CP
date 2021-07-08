
#include <bits/stdc++.h>

using namespace std;

typedef long long lo;

typedef vector<lo> vl;

typedef vector<vl>vll;

#define all(v) (v).begin(), (v).end()

#define debug(x) cerr<<#x<<" = "<<x<<endl;

#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) 

#define REP(a,b) for(lo i =(a) ;i<(b);i++)



int solve(vector<int> &dice1, vector<int>&dice2){
	
	lo sum1=0;
        lo  N = dice1.size(), M = dice2.size();
	for(int i=0; i< N; i++)
		sum1+=dice1[i];
	lo sum2 = 0;
	for(int i=0; i<M; i++)
		sum2+=dice2[i];
	lo diff = sum1-sum2;
	priority_queue<lo, vector<lo>> maxheap;
	priority_queue<lo, vector<lo>> minheap;

	if(diff==0)
		return 0;
	else if(diff<0){
		for(int i=0; i<N; i++)
			minheap.push(-dice1[i]);
		for(int i=0; i<M; i++)
			maxheap.push(dice2[i]);
	}
	else{
		for(int i=0; i<N; i++)
			maxheap.push(dice1[i]);
		for(int i=0; i<M; i++)
			minheap.push(-dice2[i]);
	}

	diff = abs(diff);
	lo cnt=0;
	lo val=0;
	while(val<diff){
		lo val_from_min = abs(minheap.top());
		lo val_from_max = abs(maxheap.top());
		if(val_from_min==6 && val_from_max==1)
			return -1;
		lo diff_if_min=6-val_from_min;
		lo diff_if_max=val_from_max-1;
		cnt++;
		val += max(diff_if_min, diff_if_max);
		if(diff_if_min > diff_if_max){
			minheap.pop();
			minheap.push(-6);
		}
		else{
			maxheap.pop();
			maxheap.push(1);
		}
	}
	return cnt;
}

int solution(vector<int> &A, vector<int> &B) {
   return solve(A, B);
}



int main()
{
   vector<int>A {4, 4, 4, 4, 4, 4, 4} ;
   vector<int>B{2};

   cout <<  solution(A, B);

	return 0;

}