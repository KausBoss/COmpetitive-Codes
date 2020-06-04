class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26]={0}, mag[26]={0};
        for(auto x:magazine){
        	mag[x-'a']++;
        }
        for(auto x:ransomNote){
        	freq[x-'a']++;
        	if(freq[x-'a'] > mag[x-'a']){return false;}
        }
        return true;
    }
};