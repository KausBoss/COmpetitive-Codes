#include <bits/stdc++.h>

using namespace std;

int m;
string s;
int dp[ (1<<18)+1 ][ 100 ];

int solve(int mask, int mod){
	//base case
	if(mask == ((1<<s.length())-1)){
		return mod==0;
	}
	//recursive case
	if(dp[mask][mod]!=-1){ return dp[mask][mod];}
	bool ch[10]={0};
	int ans =0;
	for(int i=0; i<s.length(); i++){
		if(mask == 0 && s[i]=='0'){// leading zero hatane ke liye
			continue;
		}
		if(!ch[s[i]-'0'] && !(mask&(1<<i))){
			ch[s[i]-'0']=1;
			ans += solve(mask|(1<<i), (10*mod + (s[i]-'0'))%m);
		}
	}
	return dp[mask][mod] = ans;
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		cin>>m;
		memset(dp, -1, sizeof(dp));
		cout<<solve(0, 0)<<endl;
	}
}