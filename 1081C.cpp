#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 998244353
#define max 2001

// ll ways(ll i, ll diff, ll prev){
// 	//base case
// 	if(i == n){
// 		return diff==0;
// 	}
// 	//recursive case
// 	if(dp[i][diff]!=-1){return dp[i][diff];}
// 	ll ans= (i!=0)? (ways(i+1, diff, prev))%mod: 0;
// 	for(int j=1; j<=m; j++){
// 		if(j!=prev && diff>0|| (i==0)){
// 			ans += ways(i+1,(i!=0)?diff-1:diff, j);
// 			ans %= mod;
// 		}
// 	}
// 	return dp[i][diff] = ans;
// }


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n, m, k;
	ll dp[max][max]={0};
	cin>>n>>m>>k;
	dp[1][0]=m;
	for(int i=1; i<n; i++){
		for(int j=0; j<=k; j++){
			dp[i+1][j] += dp[i][j];
			dp[i+1][j] %= mod;
			dp[i+1][j+1] += ((m-1)*dp[i][j])%mod;
			dp[i+1][j+1] %= mod; 
		}
	}
	cout<<dp[n][k];
}