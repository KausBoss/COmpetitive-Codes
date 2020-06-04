#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll t, n;
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1; i<=n/2	; i++){
			ll tow = log2((n+i)/i);
			ll comp = pow(2, tow);
			if(comp == (n+i)/i && tow>=2){
				cout<<i<<endl;
				break;
			}
		}
	}
}