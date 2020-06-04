#include <bits/stdc++.h>

using namespace std;

#define ll long long

int reccsum(int *a, int i, int n){
	//base case
	if(i==n){
		return 0;
	}
	//recusrive case
	return a[i] + reccsum(a, i+1, n);
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t, n, a[1000];
	cin>>t;
	for(int p=1; p<=t; p++){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		cout<<"Case "<<p<<": ";
		cout<<reccsum(a, 0, n)<<endl;
	}

}