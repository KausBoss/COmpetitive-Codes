/*
Bellman Ford Algorithm
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

template<typename T>
class graph{
	ll v;//number of vertices
	unordered_map<T, list<pair<T, ll>>> m;
public:
	graph(ll V){
		this->v = V;
	}
	void addEdge(T a, T b, ll cost, bool bidir=false){
		m[a].pb({b, cost});
		if(bidir){
			m[b].pb({a, cost});
		}
	}

	void Bellman(T src){
		unordered_map<T, ll> dist;

		for(ll i=0; i<v; i++){
			dist[i] = INT_MAX;// initializing all vertices to inf
		}
		dist[src]=0;

		//repeating relaxation for v-1 times
		for(ll i=0; i<v-1; i++){
			for(auto node:m){
				for(auto child:node.si){
					if(dist[node.fi]!= INT_MAX && (dist[child.fi] > dist[node.fi] + child.si) ){
						dist[child.fi] = dist[node.fi] + child.si;
					}
				}
			}
		}
		//after relaxing vetrices v-1 times, we check for nnegative cycle
		//by relaxing one more time
		for(auto node:m){
			for(auto child:node.si){
				if(dist[node.fi]!= INT_MAX && (dist[child.fi] > dist[node.fi] + child.si) ){
					cout<<"Negative Cycle exists\n";
					return;
				}
			}
		}

		for(auto x:dist){
			cout<<"distance from "<<src+1<<" to "<<x.fi+1<<" is "<<x.si<<endl;
		}

	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll vertex;
	cin>>vertex;
	graph<int> g(vertex);
	ll m; //number of edges
	cin>>m;
	for(ll i=0; i<m; i++){
		ll u, v, w;
		cin>>u>>v>>w;
		u--; v--;
		g.addEdge(u, v, w);
	}

	g.Bellman(0);
}