#include <bits/stdc++.h>

using namespace std;
#define ll long long int

void func(){
	string s;
	cin>>s;
	int n=s.length();
	bool seen[4] = {0,0,0,0};
	int last[4];
	int ans=INT_MAX;
	for(int i=0; i<n; i++){
		last[s[i]-'0']=i;
		seen[s[i]-'0']=1;
		if(seen[1] && seen[2] && seen[3]){
			int late = min(last[1], min(last[2], last[3]));
			ans = min(ans, i-late+1);
		}
	}
	if(ans == INT_MAX){
		cout<<0<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		func();
	}
}