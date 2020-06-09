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
const ll inf = 1e16+5;
const int mod = 1e9+7;

template<typename T>
class graph{
	ll n;
	unordered_map<T, list<pair<T, ll>>> m;
	vector<ll> dist;
public:
	graph(ll n){
		this->n=n;
		dist.resize(n, inf);
	}
	ll get(ll i){
		return dist[i];
	}
	void AddEdge(T a, T b, ll cost){
		m[a].pb(mp(b, cost));
	}
	void Dijkstra(T src){
		vector<bool> visted(n, 0);
		dist[src] = 0;
		priority_queue<pair<ll,ll>> q;
		q.push({0,src});

		while(!q.empty()){
			ll node = q.top().si;
			q.pop();
			if(visted[node]){continue;}
			visted[node]=1;

			for(auto child:m[node]){
				if(dist[child.fi] > dist[node] + child.si){
					dist[child.fi] = dist[node] + child.si;
					q.push({-dist[child.fi], child.fi});
				}
			}
		}
	}
	void clear(){
		m.clear();
		dist.clear();
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll t, ct=1;;
	cin>>t;
	while(t--){
		ll n, m, x, q;
		cout<<"Case "<<ct++<<":\n";
		cin>>n>>m>>x>>q;
		x--;		
		graph<ll> g(n), tg(n);
		for(ll i=0; i<m; i++){
			ll u, v, w;
			cin>>u>>v>>w;
			u--; v--;
			g.AddEdge(u, v, w);
			tg.AddEdge(v, u, w);
		}

		g.Dijkstra(x);
		tg.Dijkstra(x);

		for(ll i=0; i<q; i++){
			ll s, d;
			cin>>s>>d;
			s--; d--;
			ll ans = tg.get(s) + g.get(d);
			if(ans >= inf){
				cout<<"Be seeing ya, John\n";
			}
			else{
				cout<<ans<<"\n";
			}
		}
		g.clear();
	}
}