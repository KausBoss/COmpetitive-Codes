class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n= words.size();
        int *mask = new int[n];
        for(int i=0; i<n; i++){
        	mask[i]=0;
        	string s=words[i];
        	for(auto x:s){
        		mask[i] = mask[i]|(1<<(x-'a'));
        	}
        }
        int ans=0;
        for(int i=0; i<n-1; i++){
        	for(int j=i+1; j<n; j++){
        		if((mask[i]&mask[j])==0){
                    int prod = (words[i].length())*(words[j].length());
        			ans = max(ans, prod);
        		}
        	}
        }
        return ans;
    }
};