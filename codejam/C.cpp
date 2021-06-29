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


	int solve1(vector<lo>v){
			
			int cost = 0;
			int N = (int)v.size();

			for(int i = 0; i < N - 1; i++)
			{
				int index = i, min_val = v[i];

				for(int j = i + 1; j < N; j++)
				{
					if(v[j] < min_val)
					{
						min_val = v[j];
						index = j;
					}

				}

				reverse(v.begin()+i, v.begin()+index+1);

				cost += (index-i+1);
			}
			
			return cost;
	}

		void solve2(vector<lo>nums,int N, int C, vector<lo>&res){
			
			if(N>=nums.size()){
				int cost = solve1(nums);

				// debug(cost);

				// for(auto a : nums)debug(a);

				if(cost == C )res = nums;
				return;
			}
			
			for(int i = N; i < nums.size(); i++)
			{
				swap(nums[i], nums[N]);
				
				solve2(nums, N + 1, C, res);
				
				swap(nums[i], nums[N]);
			}
			
		}

		void solve()
		{
			lo N, C;
			cin >> N >> C;
			vl v;
			for(int i = 1; i <= N; i++)v.push_back(i);
			vl res;
			solve2(v, 0, C, res);

			if(res.size() == 0){cout << "IMPOSSIBLE" << endl;return;}

			for(int i = 0; i < res.size(); i++)cout << res[i] << " ";
			cout << endl;
		}

	int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cout.precision(20);
		lo T, i = 1;

		cin >> T;

		while(T--)
		{
			cout << "Case #"<<i<<": ";
			solve();
			i++;
		
		}
		return 0;
	}