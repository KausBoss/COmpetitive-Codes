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
	vector<ll> ans;
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(ll i=1; i*i<=n*n; i++){
			if((n*n)%i==0){
				ans.push_back(n+i);
				//cout<<"A :"<<n+i<<" and "<<"B :"<<((n*n+n*i)/i)<<endl;
			}
		}
		cout<<ans.size()<<endl;
		for(ll i=0; i<ans.size(); i++){
			cout<<ans[i]<<"\n";
		}
		ans.clear();
		//cout<<endl<<endl;
	}
}