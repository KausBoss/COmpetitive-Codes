#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define inf 100005
ll dp[inf];
ll pre[inf];
ll k;

ll func(ll i){
	//base case
	if(i == 0){
		return 1;
	}
	//recursive case
	if(dp[i]!=-1){return dp[i];}

	ll op1 = func(i-1);
	ll op2 = i>=k?func(i-k):0;

	return dp[i] = (op1 + op2)%mod;
}

void pehle(){
	memset(dp, -1, sizeof dp);
	pre[0]=0;
	for(int i=1;i<inf;i++){
		pre[i]=(pre[i-1]+func(i))%mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t>>k;
	pehle();
	while(t--){
		ll a, b;
		cin>>a>>b;
		cout<<(pre[b]+mod-pre[a-1])%mod<<endl;
	}
}