#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define size 100001
ll *weight, *price;
ll dp[101][size];
ll n, capacity;

ll Knapsack2(ll max_profit){
	ll inf = 1e11;
	for(ll N=0; N<=n; N++){
		for(ll profit=0; profit<=max_profit; profit++){
			if(N==0 && profit==0){
				dp[N][profit]=0;
			}
			else if(N == 0){
				dp[N][profit]=inf;
			}
			else if(price[N-1]<=profit){
				dp[N][profit]= min(weight[N-1]+dp[N-1][profit-price[N-1]], dp[N-1][profit]);
			}
			else{
				dp[N][profit]= dp[N-1][profit];
			}

		}
	}
	ll ans=0;
	for(int i=0; i<=max_profit; i++){
		if(dp[n][i]<=capacity){
			ans =i;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>capacity;
	weight = new ll[n];
	price = new ll[n];
	ll max_profit=0;
	for(int i=0; i<n; i++){
		cin>>weight[i]>>price[i];
		max_profit += price[i];
	}

	cout<<Knapsack2(max_profit)<<endl;
	
}