/*
Kruskal's Algorithm with comments
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

vector<vector<ll>> edges;

class dsu{
	vector<ll> parent, rank;
	ll total_component;
public:
	dsu(int n){
		parent.resize(n);
		rank.resize(n);
		for(int i=0; i<n; i++){
			parent[i] = i;
			rank[i] = 0;
		}
		total_component = n;
	}

	ll get(ll a){
		if(parent[a] == a){
			return a;
		}
		
		return parent[a] = get(parent[a]);
	}

	void union_set(ll a, ll b){
		a = get(a);
		b = get(b);
		if(a != b){
			if(rank[a] < rank[b]){
				swap(a, b);
			}
			parent[b] = a;
			if(rank[a] == rank[b]){
				rank[a]++;
			}
			total_component--;
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
	for(int i=0; i<m; i++){
		ll u, v, w;
		cin>>u>>v>>w;// vertA, VertB, weight
		u--;v--; //because dsu would be 0 indexed
		edges.pb({w, u, v});
	}
	sort(edges.begin(), edges.end());//sorting according to weight of the edge
	ll cost_mst=0;
	map<ll, list<ll>> mp;// to stroe the final spanning tree
	dsu g(n);
	for(auto x:edges){
		ll weight=x[0];//weight of the edge
		ll u = x[1]; //first node
		ll v = x[2];//second node
		//checking if both vertices are not connected
		if(g.get(u) != g.get(v)){
			g.union_set(u, v);
			cost_mst += weight;
			mp[u].pb(v);
		}
	}
	cout<<"Minimum cost is "<<cost_mst<<endl;
	for(auto x:mp){
		for(auto y:x.si){
			cout<<x.fi+1<<" is connected to "<<y+1<<endl;
		}
	}
}