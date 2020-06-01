class Solution {
public:
    vector<int> diStringMatch(string S) {
        int l=0;// for increase
        int h=S.size();//for decrease
        vector<int> ans;
        for(int i=0; i<S.size(); i++){
        	if(S[i] == 'I'){
        		ans.push_back(l++);// whenever we encounter an I we pb l and increment it
        	}
        	else{
        		ans.push_back(h--);
        	}
        }
        ans.push_back(l);
        return ans;
    }
};