class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int i=0; i<=num; i++){
        	for(int j=0; j<12; j++){
        		if(__builtin_popcount(j) == i){
        			for(int k=0; k<60; k++){
        				if(__builtin_popcount(k) == (num - i)){
        					string temp = to_string(j);
        					temp += ':';
                            if(k<10){temp += '0';}
        					temp += to_string(k);
        					ans.push_back(temp);
        				}
        			}
        		}
        	}
        }
        return ans;
    }
};