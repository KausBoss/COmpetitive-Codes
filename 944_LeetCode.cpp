class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n=A[0].length();
        vector<string> id;
        for(int i=0; i<n; i++){
        	string temp="";
        	for(int j=0; j<A.size(); j++){
        		temp += A[j][i];
        	}
        	id.push_back(temp);
        }
        int ans=0;
        for(auto x:id){
            //cout<<x<<endl;
        	for(int i=1; i<x.length(); i++){
        		if(x[i]<x[i-1]){
                    ans++;
        		    break;   
                }
        	}
        }
        return ans;
    }
};