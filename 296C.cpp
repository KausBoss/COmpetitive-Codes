#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(ll i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(ll i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(ll i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(ll i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(ll i=0;i<n;i++){for(ll j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(ll i=1;i<=n;i++){for(ll j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(ll i=0;i<n;i++){for(ll j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(ll i=1;i<=n;i++){for(ll j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const ll nax = 1e4+5;
const ll mod = 1e9+7;

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n, m, k;
	cin>>n>>m>>k;
	ll *a = new ll[n+1];
	ll *l = new ll[m];
	ll *r = new ll[m];
	ll *d = new ll[m];
	ll *times = new ll[m+1];// prefix array of kitni baar ith operation kia 

	F(a, n);

	for(ll i=0; i<m; i++){
		cin>>l[i]>>r[i]>>d[i];
	}

	for(ll i=0; i<m; i++){
		times[i]=0;
	}

	for(ll i=0; i<k; i++){
		ll left, right;
		cin>>left>>right;
		times[left-1]++;//left marker
		times[right]--;//right marker
	}
	ll val=0;
	for(ll i=0; i<m; i++){
		val += times[i];
		times[i] = val;// filling values to prefix sum array
		d[i] *= times[i];// instead of doing ith operation times[i] times, we are changing the value of d[i]
	}

	vector<ll> bit(n+1, 0);

	for(ll i=0; i<m; i++){
		bit[l[i]-1] += d[i];
		bit[r[i]] -= d[i];
	}
	val=0;
	for(ll i=0; i<n; i++){
		val += bit[i];
		a[i] += val;
	}

	P(a, n);
}