#include <bits/stdc++.h>

using namespace std;

#define ll long long

void func(){
	ll n, k;
	cin>>n>>k;
	if(k==1){cout<<"YES\n"<<n<<"\n"; return;}
	if((n-(k-1))>0 && (n-(k-1))%2==1){
		cout<<"YES\n";
		for(int i=0; i<k-1; i++){cout<<1<<" ";}
		cout<<(n-k+1)<<"\n";
		return;
	}
	else if((n-2*(k-1))>0 && (n-2*(k-1))%2==0){
		cout<<"YES\n";
		for(int i=0; i<k-1; i++){cout<<2<<" ";}
		cout<<(n-2*(k-1))<<"\n";
		return;
	}
	else{
		cout<<"NO\n";
		return;
	}
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