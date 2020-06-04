#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n;
	cin>>n;
	ll car[n][3], dp[n][3]={0};
	for(ll i=0; i<n; i++){
		cin>>car[i][0]>>car[i][1]>>car[i][2];
	}
	dp[0][0]=car[0][0];
	dp[0][1]=car[0][1];
	dp[0][2]=car[0][2];

	for(ll i=1; i<n; i++){
			dp[i][0] = car[i][0] + min(dp[i-1][1], dp[i-1][2]);

			dp[i][1] = car[i][1] + min(dp[i-1][0], dp[i-1][2]);

			dp[i][2] = car[i][2] + min(dp[i-1][0], dp[i-1][1]);
	}
	cout<<min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));

}