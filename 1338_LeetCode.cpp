#define nax (int)1e5+3
class Solution {
public:
    int minSetSize(vector<int> arr) {
        priority_queue<int> p;
        int freq[nax]={0};
        int n=arr.size();
        for(int i=0; i<n; i++){
        	freq[arr[i]]++;
        }
        for(int i=1; i<nax; i++){
        	p.push(freq[i]);
        }
        int ans=0;
        int rem=0;
        while(rem < (n/2)){
        	ans++;
        	rem += p.top();
        	p.pop();
        }
        return ans;
    }
};