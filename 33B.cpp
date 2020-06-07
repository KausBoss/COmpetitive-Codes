/*
Floyd Warshall
*/
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
	string a, b;
	cin>>a>>b;
	if(a.length() != b.length()){
		cout<<-1;
		return 0;
	}
	vector<vector<ll>> dp(26, vector<ll>(26, INT_MAX));
	for(ll i=0; i<26; i++){
		dp[i][i]=0;
	}
	int m;
	cin>>m;
	for(int i=0; i<m; i++){
		char x, y;
		ll w;
		cin>>x>>y>>w;
		dp[x-'a'][y-'a']=min(dp[x-'a'][y-'a'] ,w);
	}
	for(int k=0; k<26; k++){
		for(int i=0; i<26; i++){
			for(int j=0; j<26; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	string st="";
	ll ans=0;
	// PNF(dp, 26, 26);
	for(int i=0; i<a.length(); i++){
		if(a[i] != b[i]){
			char minchar='.';
			ll min_cost=INT_MAX-1;
			for(int j=0; j<26; j++){
				if(dp[a[i]-'a'][j] + dp[b[i]-'a'][j] < min_cost){
					min_cost = dp[a[i]-'a'][j] + dp[b[i]-'a'][j];
					minchar = 'a'+j;
				}
			}
			if(minchar == '.'){
				cout<<-1;
				return 0;
			}
			st.pb(minchar);
			 ans += min_cost;
		}
		else{
			st.pb(a[i]);
		}
	}
	cout<<ans<<endl<<st;
}