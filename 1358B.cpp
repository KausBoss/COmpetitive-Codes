#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 2e5+5;
const int mod = 1e9+7;

ll func(){
	int n;
	cin>>n;
	vector<int> a(n);
	F(a, n);
	map<int,int> freq;
	// vector<int> freq(nax, 0);
	for(int i=0; i<n; i++){
		if(freq.count(a[i])){
			freq[a[i]]++;
		}
		else{
			freq[a[i]]=1;
		}
		//freq[a[i]]++;
	}
	// priority_queue<pair<int,int>> p;
	int prt =1;
	int past=0;
	for(auto x:freq){
		if(prt + past + x.second >= x.first+1){
			prt += (x.second + past);
			past = 0;
		}
		else{
			past += x.second;
		}
	}
	// for(int i=1; i<nax; i++){
	// 	if(freq[i]!=0){
	// 		if(freq[i]+prt+past >= i+1){
	// 			prt += (freq[i]+past);
	// 			past = 0; 
	// 		}
	// 		else{
	// 			past += freq[i];
	// 		}
	// 	}
	// }
	return prt;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		cout<<func()<<endl;
	}
}