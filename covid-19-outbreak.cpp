/*
link: https://toph.co/p/covid-19-outbreak
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
const int nax = 1e6+5;
const int mod = 1e9+7;
vector<vector<pair<ll,ll>>> m;
vector<ll> trucks;

ll dfs(ll node, bitset<nax> &visited){
	visited[node]=1;
	ll res=trucks[node];
	for(auto child: m[node]){
		if(!visited[child.fi]){
			res += min(child.si, dfs(child.fi, visited));
		}
	}
	return res;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n, z;
	cin>>n>>z;
	z--;
	m.resize(n);
	trucks.resize(n);

	for(ll i=0; i<n-1; i++){
		ll u, v, w;
		cin>>u>>v>>w;
		u--; v--;
		m[u].pb({v, w});
		m[v].pb({u, w});
	}

	F(trucks, n);

	bitset<nax> visited;

	cout<<dfs(z, visited);

}