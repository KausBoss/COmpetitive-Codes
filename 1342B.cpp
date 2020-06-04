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
	int t;
	cin>>t;
	while(t--){
		string s, ans;
		cin>>s;
		int czero=0, cone=0;
		for(int i=0; i<s.length(); i++){
			if(s[i]=='0'){czero++;}
			else{cone++;}
		}
		if(czero==0 || cone==0){
			cout<<s<<endl;
			continue;
		}
		if(s[0]=='0'){ans="01";}
		else{ans="10";}
		for(int i=0; i<s.length(); i++){
			cout<<ans;
		}
		cout<<endl;

	}
}