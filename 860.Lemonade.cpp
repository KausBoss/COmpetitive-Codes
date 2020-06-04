class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int freq[2]={0};
        
        for(int i=0;i<bills.size(); i++){
        	if(bills[i]==5){
        		freq[0]++;
        	}
        	if(bills[i]==10){
        		if(freq[0]==0){return false;}
        		freq[1]++;
        		freq[0]--;
        	}
        	if(bills[i]==20){
        		if(freq[0]==0){return false;}
        		if(freq[1]==0&&freq[0]<3){return false;}
        		freq[0]--;
        		if(freq[1]){freq[1]--;}
        		else{freq[0]-=2;}
        	}
        }
        return true;
    }
};