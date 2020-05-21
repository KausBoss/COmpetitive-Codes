class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<bool> s(32, 0);
        for(int i=0; i<32; i++){
        	if((n>>i)&1){
        		s[i]=1;
        	}
        }
        reverse(s.begin(), s.end());
        int ans=0;
        for(int i=0; i<32; i++){
        	if(s[i]){
        		ans |= (1<<i);
        	}
        }
        return ans;
    }
};