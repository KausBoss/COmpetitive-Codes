class Solution {
public:
	static bool sorty(vector<int> &a, vector<int> &b){
		return a[1]<b[1];
	}
    int eraseOverlapIntervals(vector<vector<int>> I) {
        if(I.empty()|| I.size()==1){return 0;}
        sort(I.begin(), I.end(), sorty);
        int ans=0;
        int end=I[0][1];
        for(int i=1; i<I.size(); i++){
        	if(I[i][0]>=end){
        		end=I[i][1];
        	}
        	else{
        		ans++;
        	}
        }
        return ans;
    }
};