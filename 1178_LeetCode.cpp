class Solution {
public:
    vector<int> findNumOfValidWords(vector<string> words, vector<string> puzzles){
        unordered_map<int, int> m;
        for(auto x: words){
        	int mask=0;
        	for(auto y: x){
        		mask |= (1<<(y-'a'));
        	}
        	if(m.count(mask)){m[mask]++;}
        	else{ 
        		m[mask]=1;
        		}

        }

        vector<int> ans(puzzles.size(), 0);

        for(int i=0; i<puzzles.size(); i++){
        	for(int j=0; j<(1<<7); j++){
        		int mask=0;
        		int pos=0;
        		int dig=j;
        		while(dig > 0){
        			if(dig & 1){
        				mask |= (1<<(puzzles[i][pos]-'a'));
        			}
        			pos++;
        			dig = dig>>1;
        		}
        		mask |= (1<<(puzzles[i][0]-'a'));
        		if(m.count(mask)){
        			ans[i] += m[mask];
        		}
        	}
        	ans[i] /=2;
        }
        return ans;
    }
};