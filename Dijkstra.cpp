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
	unordered_map<T, list<pair<T, ll>>> h;
public:
	void addEdge(T u, T v, ll dist){
		h[u].pb({v, dist});
		h[v].pb({u, dist});
	}

	void Dijkstra(T src){
		unordered_map<T, ll> dist;
		set<pair<ll, T>> s;
		for(auto node:h){
			dist[node.fi]= INT_MAX;
		}
		dist[src]=0;
		s.insert({0, src});

		while(!s.empty()){
			auto p = *(s.begin());
			s.erase(*s.begin());
			T node = p.si;
			ll nodeDist = p.fi;

			for(auto child:h[node]){
				if(dist[child.fi] > dist[node] +child.si){
					auto f = s.find({dist[child.fi], child.fi});
					if(f!=s.end()){
						s.erase(f);
					}
					dist[child.fi] = dist[node] + child.si;
					s.insert({dist[child.fi], child.fi});
				}
			}
		}
		for(auto node:h){
			cout<<src<<" to "<<node.fi<<" "<<dist[node.fi]<<endl;
		}
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll m;
	cin>>m;
	graph<char> g;
	for(int i=0; i<m; i++){
		char u, v; 
		ll w;
		cin>>u>>v>>w;
		g.addEdge(u, v, w);
	}
	g.Dijkstra('A');
	
}
/*
5
A B 1
A D 4
A C 8
B D 2 
D C 3
*/