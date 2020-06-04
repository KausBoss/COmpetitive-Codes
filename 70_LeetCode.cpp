class Solution {
	int dp[100000];
public:
	Solution(){
		memset(dp, -1, sizeof(dp));
		dp[0]=1;
	}
    int climbStairs(int n) {
        //base case
        if(n<0){return 0;}
        if(n==0){
        	return 1;
        }
        //recursive case
        if(dp[n]!=-1){return dp[n];}

        dp[n]= climbStairs(n-1)+ climbStairs(n-2);
        return dp[n];
    }
};