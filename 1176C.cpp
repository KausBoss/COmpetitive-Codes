#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll arr[] = {4, 8, 15, 16, 23, 42};
	unordered_map <ll, ll> m;
	for(ll i=0; i<6; i++){
		m[arr[i]]=0;
	}
	ll n;
	cin>>n;
	ll *a = new ll[n];
	for(ll i=0; i<n; i++){
		cin>>a[i];
	}
	ll j=0;
	for(ll i=0; i<n; i++){
		if(a[i] == 4){
			m[a[i]]++;
		}
		else{
			if(a[i]==8 && m[4] > m[8]){
				m[8]++;
			}
			if(a[i]==15 && m[8] > m[15]){
				m[15]++;
			}
			if(a[i]==16 && m[15] > m[16]){
				m[16]++;
			}
			if(a[i]==23 && m[16] > m[23]){
				m[23]++;
			}
			if(a[i]==42 && m[23] > m[42]){
				m[42]++;
			}
		}
	}
	ll minfreq=1e13;
	for(auto x:m){
		minfreq = min(minfreq, x.second);
	}
	//if(n == 500000)
	//cout<<minfreq<<endl;
	//ll ans =  n >= (minfreq*6) ? (n - (minfreq*6)) : n;
	cout<<(n - (minfreq*6));

}