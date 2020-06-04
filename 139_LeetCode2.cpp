class Solution {
public:
	unordered_map<string,bool> m;
	int dp*;
	bool func(string s, int pos){
		//base case
		if(pos == s.length()){
			return 1;
		}
		//recursive case
		if(dp[pos]!=-1){return dp[pos];}
		for(int end=pos+1; end<s.length(); end++){
			string x= s.substr(pos, end-pos);
			if(m.count(x) && func(s, end)){
				return dp[pos]=1;
			}
		}
		return dp[pos]=0;
	}
    bool wordBreak(string s, vector<string>& wordDict) {
        dp= new int[s.length()];
        for(int i=0; i<s.length(); i++){
        	dp[i]=-1;
        }
        for(auto x:wordDict){
        	m[x]=true;
        }
        return func(s, 0);
    }
};