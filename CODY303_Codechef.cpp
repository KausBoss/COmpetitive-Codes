#include <bits/stdc++.h>

using namespace std;

#define ll long long
int dp[101][10004];
int n, m, a[101];

int ways(int i, int sum){
	//base case
	if(i == n){
		return sum == m;
	}
	//recursive case
	if(dp[i][sum]!=-1){return dp[i][sum];}

	dp[i][sum] = ways(i+1, sum+a[i]) + ways(i+1, sum);

	return dp[i][sum];
}

void func(){
	cin>>n;
	cin>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<ways(0, 0)<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		memset(dp, -1, sizeof(dp));
		func();
	}
}