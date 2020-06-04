#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 200000


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<ll> eve, odd;
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n%4!=0){
			cout<<"NO\n";
			continue;
		}
		else{
			cout<<"YES\n";
			for(ll i=1; i<=n; i+=2){
				eve.push_back(i+1);
				if(i!=n-1)
				odd.push_back(i);
			}
			odd.push_back(eve.back()+ (n/2)-1);
			for(ll i=0; i<eve.size(); i++){
				cout<<eve[i]<<" ";
			}			
			for(ll i=0; i<odd.size(); i++){
				cout<<odd[i]<<" ";
			}
			cout<<"\n";
			eve.clear();
			odd.clear();
		}
	}
}