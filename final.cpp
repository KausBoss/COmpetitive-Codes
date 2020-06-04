#include <bits/stdc++.h>

using namespace std;

#define ll signed long long
#define inf 200000

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
		ll n, k;
		ll a[inf]; 
		bitset<inf> peak;
		cin>>n>>k;
		for(ll i=0; i<n; i++){
			cin>>a[i];
		}
		for(ll i=1; i<n-1; i++){
			if(a[i]>a[i-1] && a[i]>a[i+1]){
				peak[i]=1;
			}
		}
		ll mxbr=0, id=0, brk=0;

		for(int i=0; i<k-1; i++){
			if(peak[i]==1){
				brk++;
			}
		}

		for(int i=k-1; i<n; i++){
			if(peak[i]==1){
				brk++;
			}

			if(brk > mxbr){
				id= i-k+1;
				mxbr = brk;
			}
			if(peak[i-k+1] == 1){
				brk--;
			}

		}
		cout<<mxbr+1<<" "<<id+1<<endl;
	}
}