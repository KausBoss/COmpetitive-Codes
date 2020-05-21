class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> m;

        for(int i=0; i<=s-10; i++){
        	string temp = s.substr(i, 10);
        	if(m.count(temp)){
        		m[temp]++;
        	}
        	else{
        		m[temp]=1;
        	}
        }
        vector<string> ans;
        for(auto x: m){
        	if(x.second > 1){
        		ans.push_back(x.first);
        	}
        }
        return ans;
    }
};