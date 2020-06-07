/*
d[i] --- the minimum distance from vertex s to vertex i, that counted by algorithm of Dijkstra. "et's count the number of points on each edge of the graph that are on the distance l form the vertex s (and l --- the minimum distance from these points to s).

For edge (u, v):

if d[u] < l and l - d[u] < w(u, v) and w(u, v) - (l - d[u]) + d[v] > l then add to the answer the point on this edge, the distance of which to the vertex u is l - d[u];

if d[v] < l and l - d[v] < w(u, v) and w(u, v) - (l - d[v]) + d[u] > l then add to the answer the point on this edge, the distance of which to the vertex v is l - d[v];

if d[v] < l and d[u] < l and d[u] + d[v] + w(u, v) = 2 * l then add to the answer the point on this edge, the distance of which to the vertex v is l - d[v] and to the vertex u is l - d[u].

And if d[i] = l, then let's add to the answer this point.
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
	unordered_map<T, list<pair<T, ll>>> m;
	unordered_map<T, ll> dist;
	vector<vector<ll>> edge;
public:
	void AddEdge(T a, T b, ll cost, bool bidir= true){
		edge.pb({a, b, cost});
		m[a].pb(mp(b, cost));
		if(bidir){
			m[b].pb(mp(a, cost));
		}
	}

	void dijkstra(T src){

		for(auto x:m){ dist[x.fi]=INT_MAX;}

		set<pair<ll, T>> s;
		s.insert({0, src});
		dist[src]=0;

		while(!s.empty()){
			auto p = *s.begin();
			s.erase(p);
			T node = p.si;
			ll nodeWeight = p.fi;

			for(auto child:m[node]){
				if(dist[child.fi] > nodeWeight + child.si){
					auto ptr = s.find({dist[child.fi], child.fi});
					if(ptr != s.end()){
						s.erase(ptr);
					}
					dist[child.fi] = nodeWeight + child.si;
					s.insert({dist[child.fi], child.fi});
				}
			}
		}
	}
	ll bomb(T src, ll l){
		ll ans=0;
		for(int i=0; i<edge.size(); i++){
			ll u=edge[i][0];
			ll v=edge[i][1];
			ll w=edge[i][2];
			ll du = min(dist[u], dist[v]);
	        ll dv = max(dist[u], dist[v]);
	        //given edge is the shortest path
	        if (du + w == dv) {
	            if (du < l && dv > l){
	                ans++;
	            }
	        }
	        else {
	            if (du < l && dv < l) {
	            	//dd is the sum of requied length from both nodes to make l
	                ll dd = l + l - du - dv;
	                if (w == dd){
	                    ans++;//both meet at same point
	                }
	                else if (w > dd){
	                    ans += 2;//both have different points 
	                }
	            }
	            else if (du < l && dv >= l){
	                ans++;//other node is out of range
	            }
	        }
		}

		for(auto x:m){
			if(dist[x.fi] == l){ans++;}
		}
		return ans;
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n, m, s;
	cin>>n>>m>>s;
	graph<ll> g;
	for(int i=0; i<m; i++){
		ll x, y, w;
		cin>>x>>y>>w;
		g.AddEdge(x, y, w);
	}
	g.dijkstra(s);
	ll l;
	cin>>l;
	cout<<g.bomb(s, l);
}