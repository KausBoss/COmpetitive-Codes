class Solution {
public:
    int minFallingPathSum(vector<vector<int>> A){
    	int n=A.size();
    	for(int i=1; i<n; i++){
    		for(int j=0; j<n; j++){
    			if(j==0){
    				A[i][j] += min(A[i-1][j], A[i-1][j+1]);
    			}
    			else if(j == n-1){
    				A[i][j] += min(A[i-1][j], A[i-1][j-1]);
    			}
    			else{
    				A[i][j] += min(A[i-1][j-1], min(A[i-1][j], A[i-1][j+1]));
    			}
    		}
    	}  
    	int ans=A[n-1][0];
    	for(int i=1; i<n; i++){
    		ans = min(ans , A[n-1][i]);
    	}
    	return ans; 
    }
};