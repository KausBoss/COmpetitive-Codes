class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int n= (nums.size()+1)/2;
        for(auto x:nums){
        	if(m.count(x)){m[x]++;}
        	else{m[x]=1;}
        	if(m[x]==n){return x;}
        }
        return 1;
    }
};