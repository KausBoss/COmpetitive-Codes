/*

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
ll m;
unordered_map<ll, list<pair<ll,ll>>> g;

void BFS_0_1(ll src){
	deque<ll> q;
	q.pb(src);
	unordered_map<ll, ll> dist;
	for(auto node:g){
		dist[node.fi]=INT_MAX;
	}
	dist[src]=0;
	while(!q.empty()){
		ll node = q.front();
		q.pop_front();
		for(auto child:g[node]){
			if(dist[child.fi] == INT_MAX){
				dist[child.fi] = dist[node] + child.si;
				if(child.si){
					q.push_back(child.fi);
				}
				else{
					q.push_front(child.fi);
				}
			}
		}
	}

	for(auto x:dist){
		cout<<"distance btw "<<x.fi<<" and "<<src<<" is "<<x.si<<endl; 
	}
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>m;
	for(int i=0; i<m; i++){
		ll u, v, w;
		cin>>u>>v>>w;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	BFS_0_1(0);
}