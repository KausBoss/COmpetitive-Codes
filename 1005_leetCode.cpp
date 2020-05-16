class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
    	if(A.empty()){ return 0;}
        priority_queue<int, vector<int>, greater<int>> p;
        for(auto x:A){
        	p.push(x);
        }
        while(K>0){
        	int temp = p.top();
        	p.pop();
        	p.push(-temp);
            K--;
        }
        int ans=0;
        while(!p.empty()){
        	ans += p.top();
        	p.pop();
        }
        return ans;
    }
};