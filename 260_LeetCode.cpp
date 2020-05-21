class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0, n1=0, n2=0;
        for(auto x: nums){
        	xr ^= x;
        }
        xr &= -xr;

        for(auto x: nums){
        	if(x & xr){
        		n1 ^=x;
        	}
        	else{
        		n2 ^=x;
        	}
        }
        return {n1, n2};
    }
};