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
	ll n, l;
	cin>>n>>l;
	vector<ll> c(n);
	vector<ll> quantity(n, 0); 
	F(c, n);
	ll L= l;
	for(ll i=n-1; i>=0; i--){
		ll num = 1ll<<i;
		if(l >= num){
			quantity[i] = l/num;
			l -= num * quantity[i];
		}
		if(i<n-1 && 2*c[i] <= c[i+1]){
			quantity[i] += 2*quantity[i+1];
			quantity[i+1]=0;
		}
	}
	//` P(quantity, n);
	ll vol=0;
	for(ll i=0; i<n; i++){
		vol += quantity[i]*(1<<i);
	}

	// for(ll i=1; i<n; i++){
	// 	if(c[i] <= 2*c[i-1] ){
	// 		vol -= quantity[i-1]*(1<<(i-1));
	// 		ll left = L-vol;
	// 		ll adder = ceil((double)left/(1<<i));
	// 		quantity[i] += adder;
	// 		vol += adder*(1<<i);
	// 		quantity[i-1]=0;
	// 	}
	// }
	// vol=0;
	// for(ll i=0; i<n; i++){
	// 	vol += quantity[i]*(1<<i);
	// }
	// cout<<vol<<endl;

	// P(quantity, n);

	ll total_cost=0;
	for(ll i=0; i<n; i++){
		total_cost += quantity[i]*c[i];
	}

	ll q_back = quantity[0];
	ll c_back = c[0]*quantity[0];

	for(int i=1; i<n; i++){
		q_back += quantity[i]*(1<<i);
	}
	cout<<q_back<<endl;
	q_back = quantity[0];

	for(ll i=1; i<n; i++){
		ll make = ceil((double)q_back/(1<<i));
		if(c[i]*make < c_back){
			total_cost -= c_back;
			total_cost += c[i]*make;
			quantity[i] += make;
			c_back = 0;
			q_back = 0;
		}
		c_back += c[i]*quantity[i];
		q_back += quantity[i]*(1<<i);
	}
	cout<<q_back<<endl;
	cout<<total_cost;
}