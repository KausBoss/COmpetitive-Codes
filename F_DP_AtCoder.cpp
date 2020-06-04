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
	string s, t;
	int slen, tlen, dp[3005][3005]={0};
	cin>>s;
	cin>>t;
	slen = s.length();
	tlen = t.length();
	s = " "+s;
	t = " "+t;
	for(int i=1; i<=slen; i++){
		for(int j=1; j<=tlen; j++){
			if(s[i] == t[j]){
				dp[i][j]= dp[i-1][j-1] +1;
			}
			else{
				dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	// cout<<"  ";
	// for(auto x:t){
	// 	cout<<x<<" ";
	// }
	// cout<<endl;
	// for(int i=0;i<=slen; i++){
	// 	cout<<s[i]<<" ";
	// 	for(int j=0; j<=tlen; j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	vector<char> ans;
	int i=slen, j=tlen;
	while(i>0 && j>0){
		while(i>0 && dp[i-1][j] == dp[i][j]){i--;}
		while(j>0 && dp[i][j-1] == dp[i][j]){j--;}

		ans.push_back(s[i]);
		i--; j--;
	}
	reverse(ans.begin(), ans.end());
	for(auto x:ans){cout<<x;}
}