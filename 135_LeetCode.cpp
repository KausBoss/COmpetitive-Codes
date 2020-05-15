class Solution {
public:
    int candy(vector<int> r) {
        int n=r.size();
        vector<int> ans(n,1);
        for(int i=1; i<n; i++){
        	if(r[i]>r[i-1]){
        		ans[i]=ans[i-1]+1;
        	}
        }
        for(int i=n-2; i>=0; i--){
        	if(r[i]> r[i+1]){
        		ans[i]=max(ans[i], ans[i+1]+1);
        	}
        }
        int total=0;
        for(int i=0; i<n; i++){
        	total += ans[i];
        }
        return total;
    }
};