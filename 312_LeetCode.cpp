#include <bits/stdc++.h>

using namespace std;

#define ll long long

int maxCoins(vector<int> n) {
    reverse(n.begin(), n.end());
    n.push_back(1);
    reverse(n.begin(), n.end());
    n.push_back(1);
    int sz=n.size();
    vector<vector<int>> dp(sz, vector<int>(sz, 0));
    for(int i=0; i<sz; i++){dp[i][i]=n[i];}
    
    for(int m=1; m<sz-1; m++){
    	int j=m;
    	for(int i=0; i<sz-m-1; i++){
    		dp[i][j] = n[i] + dp[i+1][j];
    		for(int k=i+1; k<j; k++){
    			dp[i][j]=max(dp[i][j], (dp[i][k-1] + dp[k+1][j]) * n[k]);
    		}
    		dp[i][j]= max(dp[i][j], dp[i][j-1] + n[j]);
    		j++;
    	}
    }
    for(auto x:dp){
    	for(auto y:x){
    		cout<<y<<" ";
    	}
    	cout<<endl;
    }
    return dp[0][sz-2];
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cout<<maxCoins({3,1,5,8});
}
