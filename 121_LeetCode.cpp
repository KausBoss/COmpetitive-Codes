class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minval=INT_MAX;
        int maxProf=0;
        for(int i=0; i<prices.size(); i++){
        	minval=min(minval, prices[i]);
        	maxProf = max(maxProf, prices[i]-minval);
        }
        return maxProf;
    }
};