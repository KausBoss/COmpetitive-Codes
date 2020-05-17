class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<vector<int>> freq(3, vector<int> (7, 0));
        int n=A.size();
        for(int i=0; i<n; i++){
        	int up=A[i];
        	int dwn=B[i];
        	if(up == dwn){freq[2][dwn]++;}
        	else{
        		freq[0][up]++;
        		freq[1][dwn]++;
        	}
        }
        int ans=INT_MAX;
        for(int i=1; i<7; i++){
        	if(freq[0][i] + freq[1][i] + freq[2][i] == A.size()){
        		ans = min(ans, min(freq[0][i], freq[1][i]));
        	}
        }
        return ans==INT_MAX ? -1 : ans;
    }
};