class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        if(m.size()==0){return 0;}
        int n=m.size();
        int n2=m[0].size();
        vector<vector<int>> dp(n+1, vector<int>(n2+1, 0));
        int ans=0;
        for(int i=1; i<=n; i++){
        	for(int j=1; j<=n2; j++){
        		if(m[i-1][j-1]=='1'){
        			dp[i][j]=min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) +1;
        			ans = max(ans, dp[i][j]);
        		}
        	}
        }
        return ans*ans;
    }
};