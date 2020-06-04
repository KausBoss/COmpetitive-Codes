#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define lim 2010

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll dp[lim][lim];
	ll s[lim], t[lim];
	ll n, m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>s[i];
	}
	for(int i=1; i<=m; i++){
		cin>>t[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0]=1;
	for (int i=0;i<=n;i++) dp[i][0]=1;
	for (int j=0;j<=m;j++) dp[0][j]=1; 

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j]=dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			if(s[i] == t[j]){
				dp[i][j] += (dp[i-1][j-1])%mod;
			}
			dp[i][j] =  (dp[i][j]+mod)%mod;
		}
	}
	cout<<dp[n][m];
}