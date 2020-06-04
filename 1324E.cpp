#include <bits/stdc++.h>

using namespace std;

#define ll long long
int l, r, h, n;
int a[2002];
int dp[2002][2002];

int func(int i, int time){
	//base case
	if(i == n){
		return (time>=l&&time<=r);
	}
	//recursive case
	if(dp[i][time]!=-1){ return dp[i][time];}

	int val = max(func(i+1, (time+a[i])%h), func(i+1, (time+a[i]-1+h)%h));
	dp[i][time] = (time>=l && time<=r && i!=0)?val+1:val;

	return dp[i][time];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	memset(dp, -1, sizeof(dp));
	cin>>n>>h>>l>>r;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<func(0,0);

}