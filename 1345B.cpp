#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll BS(ll s, ll e){
	ll n=e;
	ll ret;
	while(s<=e){
		ll m=(s+e)/2;
		ll val = (m*(m+1)) + (m-1)*(m)/2;
		if(val == n){
			return val;
		}
		if(val < n){
			ret=val;
			s=m+1;
		}
		else if(val > n){
			e= m-1;
		}
	}
	//cout<<n<<" "<<ret<<endl;
	return ret;
}

void func(){
	ll n;
	cin>>n;
	ll ans=0;
	while(n>1){
		ans++;
		n = n - BS(1, n);
	}
	cout<<ans<<endl;
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