#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define POP(a) __builtin_popcountll(a)
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
	ll n, a, b;
	cin>>n>>a>>b;
	if((POP(a^b)&1) == 0){
		cout<<"NO";
		return 0;
	}
	vector<ll> p((1<<n));
	p[0] = a;
	p[p.size() -1 ] = b;
	vector<stack<ll>> bit(n+1);

	for(int i=0; i<(1<<n); i++){
		if(i!=a && i!=b){
			// cout<<POP(i)<<" "<<i<<endl;
			bit[POP(i)].push(i);
		}
	}
	for(int i=1; i<p.size()-1; i++){
		cout<<p[i-1]<<" ";
		if(POP(p[i-1]) == 0){
			p[i] = bit[1].top();
			bit[1].pop();
		}
		else if(POP(p[i-1]) == n){
			p[i] = bit[n-1].top();
			bit[n-1].pop();	
		}
		else{
			int ct = POP(p[i-1]);
			if(bit[ct-1].size() > bit[ct+1].size()){
				p[i] = bit[ct-1].top();
				bit[ct-1].pop();		
			}
			else{
				p[i] = bit[ct+1].top();
				bit[ct+1].pop();	
			}
		}
	}

	cout<<"YES\n";
	P(p, (1<<n));
}