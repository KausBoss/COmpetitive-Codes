#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll fib[43];

ll ways(ll x, ll n, ll k){
	//base case
	if(x==0&&k==0){ return 1;}
	if(x==0||k==0){ return 0;}
	if(n<0){return 0;}

	//recursive case
	if(x <= k*fib[n]){
		if(x - fib[n] >=0){
			return ways(x, n-1, k)+ ways(x-fib[n], n, k-1);
		}
		else{
			return ways(x, n-1, k);
		}
	}
	else{
		return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fib[0]=1;
	fib[1]=2;
	for(int i=2; i<43; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	ll q, k, x;
	cin>>q;
	while(q--){
		cin>>x>>k;
		cout<<ways(x, 42, k)<<"\n";
	}
}