#include <bits/stdc++.h>

using namespace std;

#define ll long long

int ans=INT_MIN;

void maxXOR(int a[], int i, int n, int val, int k, int included){
	//base case
	if(i==n){
		if(included == k){
			ans =max(ans, val);
		}
		return;
	}
	//recusrive case
	if(included<k){
		maxXOR(a, i+1, n, val^a[i], k, included+1);
	}
	maxXOR(a, i+1, n, val, k, included);
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t, n, k;
	int v[21];
	cin>>t;
	while(t--){
		ans=INT_MIN;
		cin>>n>>k;
		for(int i=0; i<n; i++){
			cin>>v[i];
		}
		maxXOR(v, 0, n, 0, k, 0);
		cout<<ans<<endl;
	}
}