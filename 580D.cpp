#include <bits/stdc++.h>

using namespace std;
#define ll long long
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
ll dp[(1ll<<(18))][18];
ll n, k, q;
ll *a;
map<pair<ll,ll>,ll> m;

ll func(ll mask, ll prev){
	//base case
	if(__builtin_popcount(mask) == k){
		return 0;
	}
	//recursive case
	if(prev!=-1 && dp[mask][prev]!=-1){ return dp[mask][prev];}
	ll ans=0;
	for(int i=0; i<n; i++){
		if(((mask)&(1<<i)) == 0){
			ll adv=0;
			if(m.count(mp(prev,i))){
				adv = m[mp(prev,i)]; 
				//cout<<adv;
			}
			ll val = adv + a[i] + func((mask|(1<<i)),i);
			ans = max( ans, val);
		}
	}
	return dp[mask][prev] = ans;
}


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>k>>q;
	a = new ll[n];
	F(a, n);
	for(int i=0; i<q; i++){
		ll x, y, z;
		cin>>x>>y>>z;
		m[mp(x-1,y-1)] = z;
	}
	memset(dp, -1, sizeof(dp));
	cout<<func(0, -1);
}