/*
Use the concept of strongly connected component
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
ll n;
vector<ll> costs;
vector<vector<ll>> g, tg;

void dfs(ll node, vector<bool> &visted, vector<ll> &topl){
	visted[node] = 1;
	for(auto child:g[node]){
		if(!visted[child]){
			dfs(child, visted, topl);
		}
	}
	topl.pb(node);
}

void tdfs(ll node, vector<bool> &visted, vector<ll> &topl){
	visted[node] = 1;
	for(auto child:tg[node]){
		if(!visted[child]){
			tdfs(child, visted, topl);
		}
	}
	topl.pb(costs[node]);
}

void SCC(){
	vector<bool> visted(n, 0);
	vector<ll> td;
	for(ll i=0; i<n; i++){
		if(!visted[i]){
			dfs(i, visted, td);
		}
	}

	for(ll i=0; i<n; i++){
		visted[i]=0;
	}
	vector<vector<ll>> comp;
	vector<ll> temp;
	for(ll i=td.size()-1; i>=0; i--){
		if(!visted[td[i]]){
			tdfs(td[i], visted, temp);
			comp.pb(temp);
			temp.clear();
		}
	}
	ll way=1;
	ll cost=0;
	for(auto x:comp){
		ll minV=INT_MAX;
		ll Count=0;
		for(auto y:x){
			if(y < minV){
				minV = y;
				Count=1;
			}
			else if(minV == y){
				Count++;
			}
		}
		cost += minV;
		way = (way*Count)%mod;
	}

	cout<<cost<<" "<<way;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	costs.resize(n);
	g.resize(n);
	tg.resize(n);
	F(costs, n);
	ll m;
	cin>>m;
	for(ll i=0; i<m; i++){
		ll u, v;
		cin>>u>>v;
		u--; v--;
		g[u].pb(v);
		tg[v].pb(u);
	}
	SCC();
}