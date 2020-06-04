class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(K==1){
        	string ans=S;
        	for(int i=1;i<S.length(); i++){
        		string temp = S;
                rotate(temp.begin(), temp.begin()+i, temp.end());
        		if(temp < ans){
        			ans= temp;
        		}
        	}
        	return ans;
        }
        else{
        	sort(S.begin(), S.end());
        	return S;
        }
    }
};