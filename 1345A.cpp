#include <bits/stdc++.h>

using namespace std;

#define ll long long

void func(){
	int n, m;
	cin>>n>>m;
	if(n==1 || m==1){cout<<"YES\n"; return;}
	if(n==2 && m==2){cout<<"YES\n"; return;}
	cout<<"NO\n";
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