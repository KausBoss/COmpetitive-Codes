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

ll func(ll l, ll r){
	if(l == r){ return l;}
	ll bit =  floor(log2(r));
	ll c = 1LL<<bit;
	if(c <= l){
		return c +func(l - c, r - c);
	}
	if(bit != 63){
		ll c2 = (1LL<<(bit+1));
		c2--;
		if(c2 == r){
			return ((1<<(bit+1)) - 1);
		}

	}
	return (c - 1);
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll L, R;
	int n;
	cin>>n;
	while(n--){
		cin>>L>>R;
		cout<<func(L, R)<<endl;
	}
}