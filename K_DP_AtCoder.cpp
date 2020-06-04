#include <bits/stdc++.h>

using namespace std;

#define ll long long
int dp[100001][2];
int n, k;
int *a;

bool func(int stones, bool player){
	//base case
	if(stones == 0){
		return !player;
	}
	//recursive case
	if(dp[stones][player]!=-1){return dp[stones][player];}

	for(int i=0; i<n; i++){
		if(a[i] <= stones && player == func(stones - a[i], !player)){
			return dp[stones][player] = player;
		}
	}

	return dp[stones][player] = (!player);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	memset(dp, -1, sizeof(dp));
	cin>>n>>k;
	a = new int[n];
	for(int i=0; i<n;i++){
		cin>>a[i];
	}
	sort(a, a+n);
	if(func(k, 1)){
		cout<<"First";
	}
	else{
		cout<<"Second";
	}
}