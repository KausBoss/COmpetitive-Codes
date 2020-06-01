class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> FreqP(26, 0);
        vector<int> FreqS(26, 0);
        for(int i=0; i<p.length(); i++){
            FreqP[p[i] - 'a']++;
        }
        vector<int> ans;
        for(int i=0; i<(p.length()-1) && i<s.length(); i++){
            FreqS[s[i] - 'a']++;
        }
        for(int i= p.length()-1; i<s.length(); i++){
            FreqS[s[i] - 'a']++;
            if(FreqS == FreqP){
                ans.push_back(i - p.length()+1);
            }
            FreqS[s[i- p.length()+1] - 'a']--;
        }
        return ans;
    }
};