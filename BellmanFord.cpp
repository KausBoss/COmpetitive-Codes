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
ll n, m;

template<typename T>
class graph{
	unordered_map<T, list<pair<T, ll>>> h;
public:
	void addEdge(T u, T v, ll dist){
		h[u].pb({v, dist});
		//h[v].pb({u, dist});
	}

	void Bellman(T src){
		unordered_map<T, ll> dist;

		for(int i=0; i<=5; i++){
			dist[i]= INT_MAX;
		}
		dist[src]=0;

		ll vert = n;
		for(ll i=0; i<vert-1; i++){
			for( auto node:h){
				T u = node.fi;
				for(auto child:h[u]){
					T v= child.fi;
					ll edge_dist= child.si;
					//dist[u] != INT_MAX -> jo update kar raha hai i.e- u can not have INT_MAX as dist
					if(dist[u] != INT_MAX && dist[v] > dist[u] + edge_dist){
						dist[v] = dist[u] + edge_dist;
					}
				}
			}
		}

		for( auto node:h){
			T u = node.fi;
			for(auto child:h[u]){
				T v= child.fi;
				ll edge_dist= child.si;
				if(dist[u] != INT_MAX && dist[v] > dist[u] + edge_dist){
					cout<<"Negative cycle present";
					return;
				}
			}
		}

		for(auto node:h){
			cout<<src<<" to "<<node.fi<<" is "<<dist[node.fi]<<endl;
		}

	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>m;
	graph<ll> g;
	for(int i=0; i<m; i++){
		ll u, v; 
		ll w;
		cin>>u>>v>>w;
		g.addEdge(u, v, w);
	}
	g.Bellman(0);
	
}