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
const int nax = 2e7+7;
vector<int> freq(nax, 0);
bitset<nax> pr;
vector<int> prefix(nax, 0);

void sieve(){
	pr[0] = pr[1] = 1;
	for(ll i=2; i<nax; i++){
		if(!pr[i]){
			prefix[i] += freq[i];
			for(ll j=2; (i*j)<nax; j++){
				pr[i*j] = 1;
				prefix[i] += freq[i*j];
			}
		}
	}
	for(ll i=2; i<nax; i++){
		prefix[i] += prefix[i-1];
	}
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n;
	cin>>n;
	for(int i=0; i<n; i++){
		ll temp;
		cin>>temp;
		freq[temp]++;
	}
	// P(freq, nax);
	sieve();
	//P(prefix, nax);
	ll m;
	cin>>m;
	while(m--){
		ll l, r;
		cin>>l>>r;
		if(l>nax){
			l = r = 1;
		}
		if(l<nax && r>nax){
			r= nax-1;
		}
		cout<<prefix[r] - prefix[l-1]<<endl;
	}
}