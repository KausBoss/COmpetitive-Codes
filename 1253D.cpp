/*
D. Harmonious Graph
idea: each disjoint component must have all the elements btw component_min to component_max
->for this we maintain a vector that stroes the maxVal in a component
for smallest value we iterate to max value
if any val is missing we combine set 
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

class dsu{
	vector<ll> parent, rank;
public:
	dsu(ll n){
		parent.resize(n);
		rank.resize(n, 0);
		for(int i=0; i<n; i++){
			parent[i] = i;
		}
	}
	ll get(ll n){
		if(parent[n] == n){
			return n;
		}
		return parent[n] = get(parent[n]);
	}
	void union_set(ll a, ll b){
		a = get(a);
		b = get(b);

		if(a != b){
			if(rank[a] < rank[b]){
				swap(a, b);
			}
			parent[b] = a;
			if(rank[a] == rank[b]){ rank[a]++;}
		}
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n, m;
	cin>>n>>m;
	dsu g(n);
	vector<ll> max_con(n);
	for(ll i=0; i<n; i++){
		max_con[i]=i;
	}

	for(int i=0; i<m; i++){
		ll x, y;
		cin>>x>>y;
		x--; y--;
		max_con[g.get(x)] = max(max_con[g.get(x)], max_con[g.get(y)]);
		max_con[g.get(y)] = max_con[g.get(x)];
		g.union_set(x, y);
	}

	ll ans=0;
	for(ll i=0; i<n;){
		ll j;
		for(j=i+1; j<max_con[g.get(i)] && j<n; j++){
			if(g.get(i) != g.get(j)){
				ans++;
				max_con[g.get(i)] = max(max_con[g.get(i)], max_con[g.get(j)]);
				g.union_set(i, j);
			}
		}
		i = j;
	}
	cout<<ans;
}