#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll ans=0;
#define mod 1000000007

ll fib[43];

void fun2(ll n, ll k, ll lastid){
	//base case
	if(n==0 && k==0){
		ans++;
		ans%=mod;
		return;
	}
	if(n==0||k==0){return;}

	//recursive case
	for(ll j=lastid; (fib[j]<=n)&&(j<43); j++){
		fun2(n-fib[j], k-1, j);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fib[0]=1; fib[1]=2;
	for(ll i=2; i<45; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	ll t,n, k;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>k;
		fun2(n, k, 2);
		cout<<ans<<"\n";
	}
}