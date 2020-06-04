#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define mod 1000000007

ll dp[10005][105][2], d;
string s;


ll solve(ll pos, ll modi, bool tight){
	//base case
	if(pos == s.length()){
		return modi==0;
	}
	//recursive case
	if(dp[pos][modi][tight]!=-1){return dp[pos][modi][tight];}

	ll ans=0;
	ll end= (tight)?(s[pos]-'0'):9;
	for(ll i=0; i<=end; i++){
		ll t = (solve(pos+1, (modi+i)%d, tight&(i==end)))%mod;
		ans += t;
		ans %= mod;
	}
	return dp[pos][modi][tight] = ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	memset(dp, -1, sizeof(dp));
	cin>>s;
	cin>>d;
	cout<<(solve(0, 0, 1)-1+mod)%mod;
}