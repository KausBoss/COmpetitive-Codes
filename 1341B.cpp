#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 205

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		ll n, a[inf], k;
		int freq[inf]={0};
		cin>>n>>k;
		for(int i=0;i<n; i++){
			cin>>a[i];
		}
		for(int i=1; i<n-1; i++){
			if(a[i]>a[i-1] && a[i]>a[i+1]){
				freq[i]=1;
			}
		}
		for(int i=1; i<n; i++){
			freq[i]=freq[i]+freq[i-1];
		}
		ll parts=freq[k-1], id=0;

		for(int i=k+1; i<n; i++){
			ll cur= freq[i-1] - freq[i-k];
			if(cur > parts){
				parts=cur;
				id=i-k;
			} 
		}
		cout<<parts+1<<" "<<id+1<<endl;
	}
}