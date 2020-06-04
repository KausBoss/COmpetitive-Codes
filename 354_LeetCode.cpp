class Solution {
public:
	bool sorty(vector<int> a, vector<int> b){
		if(a[0] == b[0]){return a[1]>b[1];}
		if(a[1] == b[1]){return a[0]>b[0];}
		return a[0]>b[0];
	}
	
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), sorty);


    }
};