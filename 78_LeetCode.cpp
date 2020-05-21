class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans((1<<n));
        for(int i=0; i<(1<<n); i++){
        	int pos=0;
            int t=i;
        	while(t > 0){
        		if(t&1){
        			ans[i].push_back(nums[pos]);
        		}
                pos++;
                t=t>>1;
        	}
        }
        return ans;
    }
};