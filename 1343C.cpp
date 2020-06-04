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
	ll t, n, a[inf];
	cin>>t;
	while(t--){
		ll ct,negm, posm, maxele;
		negm = posm = maxele = INT_MIN;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
			maxele = max(a[i], maxele);
		}
		bool neg=false;
		for(int i=0; i<n; i++){
			if(neg=false && a[i]<0){
				ct += 
			}
		}
	}
}