#include <bits/stdc++.h>

using namespace std;

#define ll long long

void func(){
	string s;
	cin>>s;
	int n=s.length();
	int cnt=0;
	for(int i=0; i<n; i++){if(s[i]!='0'){cnt++;}}
	cout<<cnt<<endl;
	for(int i=0; i<n; i++){
		if(s[i]!='0'){
			cout<<(s[i]-'0')*pow(10, n-i-1)<<" ";
		}
	}
	cout<<endl;
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
		func();
	}
}