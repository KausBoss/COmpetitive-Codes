class Solution {
public:
	int func(string a, string b, int i, int j, vector<vector<int>> &dp){
		//base case
		if(i == 0){ return j;}
		if(j == 0){ return i;}
		//recursive case
		if(dp[i][j]!=-1){return dp[i][j];}

		if(a[i] == b[j]){return dp[i][j]=func(a, b, i-1, j-1, dp);}
		else{
			return dp[i][j]= min(1+ func(a, b, i-1, j, dp), min( 1+ func(a, b, i, j-1,dp), 1+func(a,b, i-1,j-1,dp)));
		}
	}
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        word1 = " " + word1;
        word2 = " " + word2;
        return func(word1, word2, word1.length()-1, word2.length()-1, dp);
    }
};