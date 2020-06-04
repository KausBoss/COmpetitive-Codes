class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        vector<vector<int>> dp(t.size(), vector<int>(t.size(), 1));
        dp[0][0]=t[0][0];
        for(int i=1; i<t.size(); i++){
        	for(int j=0; j<=i; j++){
        		if(j==0){
        			dp[i][j]= dp[i-1][j] + t[i][j];
        		}
        		else if(j == i){
        			dp[i][j]=dp[i-1][j-1] + t[i][j];
        		}
        		else{
        			dp[i][j]= t[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
        		}
        	}
        }
        int ans=dp[t.size()-1][0];
        for(int i=1; i<t.size(); i++){
        	ans = min(ans, dp[t.size()-1][i]);
        }
        return ans;
    }
};