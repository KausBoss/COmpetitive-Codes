#include <bits/stdc++.h>

using namespace std;

#define ll long long
int ans=INT_MAX;

void func(int a, int b, int steps){
	//base case
	if(a==1 && b==1){
		ans = min(ans, steps);
		return;
	}

	if(a>b){
		func(a-b, b, steps+1);
	}

	if(b>a){
		func(a, b-a, steps+1);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	if(n==1){cout<<0; return 0;}
	for(int i=1; i<n; i++){
		func(i, n-i, 1);
	}
	cout<<ans;
}