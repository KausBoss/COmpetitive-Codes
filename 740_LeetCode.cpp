class Solution {
public:
	vector<int> a;
	map<pair<int,int>, int> dp;
	int func(int i, int freq[]){
		//base case
		if(i==a.size()){
			return 0;
		}
		//recursive case
		if(dp.count(make_pair(i, freq[a[i]]))){return dp[make_pair(i, freq[a[i]])];}

		int op1= func(i+1, freq);
		int up=freq[a[i]+1];
		int low=freq[a[i]-1];
		freq[a[i]+1]=0;
		freq[a[i]-1]=0;
		int op2= a[i]*freq[a[i]] + func(i+1, freq);
		dp[make_pair(i, freq[a[i]])] = max(op1, op2);
		freq[a[i]+1]=up;
		freq[a[i]-1]=low;
		return max(op1, op2);

	}
    int deleteAndEarn(vector<int>& nums) {
    	int freq[10005]={0};
        set<int> s;
        for(auto x:nums){freq[x]++;}
        for(int i=1; i<10005; i++){if(freq[i]){a.push_back(i);}}
        return func(0, freq);
    }
};