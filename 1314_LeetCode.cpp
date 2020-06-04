class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m=mat.size(), n=mat[0].size();
        int dp[m][n];
        for(int i=0; i<m; i++){
        	for(int j=0; j<n; j++){
        		for(int x=0; x<=i;x++){
        			for(int y=0; y<=j; y++){
        				dp[i][j] += dp[x][y];
        			}
        		}
        	}
        }

        for(int i=0; i<m; i++){
        	for(int j=0; j<n; j++){
        		
        	}
        }
    }
};