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

template<typename T>
class graph{
	ll v;
	unordered_map<T, list<pair<T, ll>>> m;
public:
	graph(ll V){
		this->v = V;
	}
	void AddEdge(T a, T b, ll cost, bool bidir=true){
		m[a].pb(mp(b, cost));
		if(bidir){
			m[b].pb(mp(a, cost));
		}
	}

	ll FindMin(unordered_map<T, bool> visited, unordered_map<T, ll> weight){
		ll minVertex = -1;
		for(ll i=0; i<v; i++){
			if(!visited[i] && (minVertex==-1 || weight[minVertex] > weight[i])){
				minVertex = i;
			}
		}
		return minVertex;
	}
	void Prims(){
		unordered_map<T, bool> visited;
		unordered_map<T, ll> weight;//to store the currrent weight of the vertices
		unordered_map<T, ll> parent;//to retrive the spannnig tree

		for(ll i=0; i<v; i++){
			weight[i]=INT_MAX;
			visited[i]=0;
		}
		//marking the vertex 0 as src
		//NOTE: we can choose any vertex to begin with
		parent[0]=-1;
		weight[0]=0;

		for(ll i=0; i<v-1; i++){
			ll minVertex = FindMin(visited, weight);//to find the unvisited vertex with minimum weight
			//after finding the min vertex, mark it visited ans relax all its neighbour
			visited[minVertex] =1;
			//iterating over its neighbout
			for(auto child:m[minVertex]){
				if(!visited[child.fi]){
					if(weight[child.fi] > child.si){
						weight[child.fi] = child.si;
						parent[child.fi] = minVertex;
					}
				}
			}			
		}0

		for(ll i=1; i<v; i++){
			cout<<i+1<<" is connect to "<<parent[i]+1<<" with cost "<<weight[i]<<endl;
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
	cin>>n>>m;//n is number of vertices and m is number of edges

	graph<ll> g(n);
	for(int i=0; i<m; i++){
		ll u, v, w;
		cin>>u>>v>>w;// vertA, VertB, weight
		u--;v--; //because dsu would be 0 indexed
		g.AddEdge(u, v, w);
	}

	g.Prims();
}