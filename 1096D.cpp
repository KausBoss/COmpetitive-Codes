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
const int nax = 1e4+5;
const int mod = 1e9+7;

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
 	ll n;
 	string s, t=" hard";
	cin>>n;
	cin>>s;
	s = ' ' + s;
	vector<ll> a(n);
	F(a, n);

	vector<vector<ll>> dp(5, vector<ll>(n+1,1e10));
	// for(int i=0; i<5; i++){
	// 	dp[i][0]=1e13;
	// }
	// for(int i=0; i<=n; i++){
	// 	dp[0][i]=1e13;
	// }
	dp[0][0]=0;
	for(ll i=1; i<t.length(); i++){
		for(ll j=1; j<s.length(); j++){
			if(t[i] == s[j]){
				dp[i][j] = min(dp[i-1][j-1], dp[i][j-1] + a[j-1]);
			}
			else{
				dp[i][j]= dp[i][j-1];
			}
		}
	}
	PNF(dp, 5, n+1);
	cout<<dp[4][n];
}		