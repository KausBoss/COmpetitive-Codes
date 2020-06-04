#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define inf 1001
vector<vector<char>> v;
vector<vector<ll>> dp;

ll ways(ll i, ll j){
	//base case
	if(i==0 && j==0){
		return 1;
	}
	//recursive case
	if(dp[i][j]!=-1){return dp[i][j];}

	ll op1=0, op2=0;

	if(j!=0 && v[i][j-1]=='.'){
		op1 = ways(i, j-1);
	}
	if(i!=0 && v[i-1][j]=='.'){
		op2 = ways(i-1, j);
	}
	dp[i][j]= (op1 + op2)%mod;
	return dp[i][j];
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll h, w;
	cin>>h>>w;
	v = vector<vector<char>> (h, vector<char>(w, ' '));
	dp = vector<vector<ll>> (h, vector<ll>(w, -1));
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin>>v[i][j];
		}
	}
	cout<<ways(h-1, w-1);
}