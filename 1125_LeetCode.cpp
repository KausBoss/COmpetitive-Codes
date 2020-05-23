class Solution {
	public:
	unordered_map<string, int> h;
	int pmask[100];
	int fmask;
	int p;
	int dp[100][(1<<16)];
	bool choose [100][(1<<16)];

	int solve(int i, int cmask){
		if(cmask == fmask){
			return 0;
		}

		if(i == p){
			return 2000;//because max can be 60 people
		}
        if(dp[i][cmask]!=-1){ return dp[i][cmask];}
		//for a perticular person we have 2 options
		//select him, or dont select him
		int inc = 1 + solve(i+1, cmask|pmask[i]);
		int exc = 0 + solve(i+1, cmask);

		if(inc < exc){
			// include ith person
			choose[i][cmask]=true;
		}
		else{
			//exclude ith person 
			choose[i][cmask] = false;
		}
		return dp[i][cmask] = min(inc, exc);
	}

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        for(int i=0; i<req_skills.size(); i++){
        	h[req_skills[i]]=i;//storing the corresponding bit
            //cout<<h[req_skills[i]]<<endl;
        }
        for(int i=0; i<people.size(); i++){
        	int mask=0;
        	for(int j=0; j<people[i].size(); j++){
                cout<<h[people[i][j]]<<endl;
        		mask |= (1<<h[people[i][j]]);
        	}
        	pmask[i]=mask;
            //cout<<mask<<endl;
        }
        memset(dp, -1, sizeof(dp));
        fmask = (1<<req_skills.size()) - 1;
        p = people.size();
        solve(0, 0);
        int mask=0;
        vector<int> ans;
        for(int i=0; i<p & mask!=fmask; i++){
        	if(choose[i][mask] == true){
        		ans.push_back(i);
        		mask |= pmask[i];
        	}
        }
        return ans;
    }
};