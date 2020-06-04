class Solution {
public:
	map<pair<int,int>, int> dp;
	int func(vector<int> a, int i, int sum, int s){
		//base case
		if(i == a.size()){
			return sum==s;
		}
		//recursive case
		if(dp.count(make_pair(i, sum))){return dp[make_pair(i, sum)];}

		dp[make_pair(i, sum)] = func(a, i+1,sum+a[i], s) + func(a, i+1, sum-a[i], s);
		return dp[make_pair(i, sum)];
	}
    int findTargetSumWays(vector<int>& nums, int S) {
    	return func(nums, 0, 0, S);
    }
};