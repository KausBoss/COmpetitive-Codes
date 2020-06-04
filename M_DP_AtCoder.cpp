//this code is giving TLE
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define inf 100005
ll *a, n;
ll dp[101][inf];

ll ways(ll i, ll left){
	//base case
	if(i==n){return left==0;}
	if(left==0){return 1;}

	//recursive case
	if(dp[i][left]!=-1){return dp[i][left];}

	dp[i][left]=0;
	for(ll j=0; j<=a[i]&&j<=left; j++){
		dp[i][left] += ways(i+1, left-j);
		dp[i][left] %= mod;
	}
	return dp[i][left];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	memset(dp, -1, sizeof(dp));
	ll k;
	cin>>n>>k;
	a = new ll[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<ways(0, k);
	
}