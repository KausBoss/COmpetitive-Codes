#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll dp[10][82][2];
string s;

// ll ways(ll i, bool tight, ll num){
// 	//base case
// 	if(i == s.length()){
// 		return 0;
// 	}
// 	//recursive case
// 	if(dp[i][tight][num]!=-1){return dp[i][tight][num];}
// 	ll end = tight ? s[i]-'0':9;
// 	ll ans=0;
// 	for(ll j=0; j<=end; j++){
// 		ans += ways(i+1, tight&(j==end), num + j);
// 	}
// 	return dp[i][tight][num] = ans;
// }

ll solve(int pos, bool tight, int sum){
    if(pos == s.length()) return sum;
    if(dp[pos][sum][tight] != -1) return dp[pos][sum][tight];
    ll ans=0;
    ll end=((tight)?(s[pos]-'0'):9);
    for(ll i=0; i<=end; i++){
        ans += solve(pos+1, tight&(i==end), sum+i);
    }
    return dp[pos][sum][tight]=ans;
}

void func(ll a, ll b){
	memset(dp, -1, sizeof dp);
	s = to_string(b);
	ll ans = solve(0, 1, 0);

	if(a>0)a--;
	memset(dp, -1, sizeof dp);
	s = to_string(a);
	ans -= solve(0, 1, 0);
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll a, b;
	cin>>a>>b;
	while(a!=-1){
		func(a, b);
		cin>>a>>b;
	}
}