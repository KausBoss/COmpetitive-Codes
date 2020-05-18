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
	ll n, l, r, x;
	cin>>n>>l>>r>>x;
	ll *ar = new ll[n];
	for(int i=0; i<n; i++){
		cin>>ar[i];
	}
	ll ans=0;
	for(ll i=3; i<(1<<n); i++){
		if(__builtin_popcountll(i)>1){
			ll mask = i;
			ll minval=1e13;
			ll maxval=-1e13;
			ll total=0;
			ll pos=0;
			while(mask > 0){
				if(mask & 1){
					total+= ar[pos];
					minval = min(ar[pos], minval);
					maxval = max(ar[pos], maxval);
				}
				pos++;
				mask = mask>>1;
			}
			if(total >= l && total <= r && (maxval-minval)>=x){
				ans++;
			}
		}
	}
	cout<<ans;
}