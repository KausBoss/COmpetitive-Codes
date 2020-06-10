/*
Strongly Connected Component
SSC
in an SSC we can go from any node to any node

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

ll n, m; //number of nodes and number of directed edges
vector<vector<ll>> g;//original graph
vector<vector<ll>> tg; //transpose of the original graph
vector<bool> visited;
vector<vector<ll>> strongComp;

void dfs(ll node, vector<bool> &visited, vector<ll> &travesal_dfs){
	visited[node] = 1;

	for(auto child:g[node]){
		if(!visited[child]){
			dfs(child, visited, travesal_dfs);
		}
	}
	travesal_dfs.pb(node);
}

void tdfs(ll node, vector<bool> &visited, vector<ll> &temp){
	visited[node] = 1;
	for(auto child:tg[node]){
		if(!visited[child]){
			tdfs(child, visited, temp);
		}
	}
	temp.pb(node);
}

void SCC(){
	vector<ll> travesal_dfs;
	for(ll i=0; i<n; i++){
		if(!visited[i]){
			dfs(i, visited, travesal_dfs);
		}
	}
	for(ll i=0; i<n; i++){
		visited[i]=0;
	}
	vector<ll> temp;
	for(ll i= travesal_dfs.size()-1; i>=0; i--){
		if(!visited[travesal_dfs[i]]){
			tdfs(travesal_dfs[i], visited, temp);
			strongComp.pb(temp);
			temp.clear();
		}
	}
	for(auto x:strongComp){
		for(auto y:x){
			cout<<y+1<<" ";
		}
		cout<<endl;
	}
}


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>m;
	g.resize(n);
	tg.resize(n);
	visited.resize(n, 0);
	for(ll i=0; i<m; i++){
		ll a, b;
		cin>>a>>b;
		a--; b--;
		g[a].pb(b);
		tg[b].pb(a);
	}
	SCC();
}