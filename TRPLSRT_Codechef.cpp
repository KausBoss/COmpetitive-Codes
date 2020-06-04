#include <bits/stdc++.h>

using namespace std;

#define ll long long
map<int,int> seedha, ulta;

void func(){
	int n, k;
	cin>>n>>k;
	int *a=new int[n+1];
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]!=i){
			seedha[a[i]]=i;
			ulta[i]=a[i];
		}
	}
	vector<vector<int>> ans;
	int turn=0;
	for(auto &x:m && turn<k){
		int id1= x.second;
		int id2= x.first;
		int id2= a[x.first];
		turn++;
		
	}
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