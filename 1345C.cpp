#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf (int)2e5

void func(){
	ll n ,a[inf], cap[inf]={0};
	cin>>n;
	for(ll i=0; i<n; i++){
		cin>>a[i];
		ll new_id= a[i]>=0?(i+a[i]%n)%n:(i+n+(a[i]%n))%n;
		cap[new_id]++; 
	}
	for(int i=0; i<n; i++){
		if(cap[i]!=1){cout<<"NO\n"; return;}
	}
	cout<<"YES\n";
	return;
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