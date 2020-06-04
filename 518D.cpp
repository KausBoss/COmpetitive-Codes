#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[ 20 ][ 4 ][ 2 ];
ll l, r;
string s;

ll solve(ll pos, ll cnt, bool tight){
	//base case
	if(pos == s.length()){
		return 1;
	}
	//recursive case
	if(dp[pos][cnt][tight]!=-1){return dp[pos][cnt][tight];}

	ll ans =0;
	ll end = (tight)?(s[pos]-'0'):9;
	for(int i=0; i<=end; i++){
		ll cntupd = cnt + (i>0);
		if(cntupd <=3){
			ans += solve(pos+1, cntupd, tight&(i==end));
		}
	}
	return dp[pos][cnt][tight] = ans;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		cin>>l>>r;
		memset(dp, -1, sizeof(dp));
		s= to_string(r);
		ll ans = solve(0, 0, 1);

		l-=1;
		memset(dp, -1, sizeof(dp));
		s = to_string(l);
		ans -= solve(0, 0, 1);
		cout<<ans<<endl;
	}
}