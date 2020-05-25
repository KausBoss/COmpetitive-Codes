#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(ll i=0;i<n;i++){cin>>a[i];}
//#define F1(a,n) for(ll i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(ll i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(ll i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(ll i=0;i<n;i++){for(ll j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(ll i=1;i<=n;i++){for(ll j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(ll i=0;i<n;i++){for(ll j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(ll i=1;i<=n;i++){for(ll j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const ll nax = 1e4+5;
#define mod 1000000007
ll k=5, n;
vector<ll> F1;
vector<ll> c({1, 2, 0, 5, 1});
vector<vector<ll>> T;

vector<vector<ll>> mul(vector<vector<ll>> ret, vector<vector<ll>> T){
	vector<vector<ll>> ans(k, vector<ll>(k, 0));

	for(ll i=0; i<k; i++){
		for(ll j=0; j<k; j++){
			for(ll l=0; l<k; l++){
				ans[i][j] += (ret[i][l]*T[l][j])%mod;
				ans[i][j] %= mod;
			}
		}
	}
	return ans;
}


vector<vector<ll>> exp(vector<vector<ll>> T, ll b){
	//base case
	if(b == 1){
		return T;
	}
	//recursive case
	if(b&1){
		return mul(T, exp(T, b-1));

	}
	vector<vector<ll> > ans = exp(T,b/2);
	return mul(ans,ans);
}

void solve(){
	//cin>>k;
	F1.resize(k);
	c.resize(k);
	T.resize(k, vector<ll>(k, 0));
	F(F1, k);
	//F(c, k);
	cin>>n;

	//P(F1, k);

	if(n<k){
		cout<<F1[n]<<endl;
		return;
	}
	for(ll i=0; i<k-1; i++){
		T[i][i+1]=1;
	}
	ll j=0;
	for(ll i=k-1; i>=0; i--){
		T[k-1][i]=c[j++];
	}
	// PNF(T, k, k);

	T = exp(T, n);

	// PNF(T, k, k);

	ll ans = 0;

	for(ll i=0; i<k; i++){
		ans += (T[0][i]*F1[i])%mod;
		ans %= mod;
	}
	cout<< ans<<endl;
}


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		solve();
		F1.clear();
		T.clear();
		//c.clear();
	}
}