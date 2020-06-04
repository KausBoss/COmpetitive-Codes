#include <bits/stdc++.h>

using namespace std;

#define ll long long

int change(int a, vector<int> c) {
    vector<int> dp(a+1, 0);
    dp[0]=1;
    for(int i=0;i<c.size(); i++){
    	for(int j=1; j<=a; j++){
    		if(j>=c[i]){
    			dp[j] +=dp[j-c[i]];
    		}
    	}
    }
    return dp[a];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cout<<change(5, {1,2,5});
}

