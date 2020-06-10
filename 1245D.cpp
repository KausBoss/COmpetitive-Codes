/*
D. Shichikuji and Power Grid
idea: consider all edges given
along with that consider node 0 as the main power supply
the cost of edge from any node to main power supply is the cost to build power station
in that city.
Include these edges as well
sort them
run Kruskal
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

class dsu{
	vector<ll> parent, rank;
public:
	dsu(ll n){
		parent.resize(n);
		rank.resize(n, 0);
		for(ll i=0; i<n; i++){
			parent[i]=i;
		}
	}
	ll get(ll n){
		if(parent[n] == n){
			return n;
		}
		return parent[n] = get(parent[n]);
	}
	void union_set(ll a, ll b){
		a = get(a);
		b = get(b);

		if(a != b){
			if(rank[a] < rank[b]){
				swap(a, b);
			}
			parent[b]=a;
			if(rank[a] == rank[b]){
				rank[a]++;
			}
		}
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n;
	cin>>n;
	vector<pair<ll,ll>> pos(n+1);

	for(ll i=1; i<=n; i++){
		ll x, y;
		cin>>x>>y;
		pos[i] = {x, y};
	}
	vector<ll> ps_cost(n+1);
	vector<ll> wire_cost(n+1);
	F1(ps_cost, n);
	F1(wire_cost, n);

	vector<vector<ll>> edge;
	for(ll i=1; i<=n-1; i++){
		for(ll j=i+1; j<=n; j++){
			edge.pb({(wire_cost[i]+wire_cost[j])*(abs(pos[i].fi - pos[j].fi) + abs(pos[i].si - pos[j].si)), i, j });
		}
	}

	for(ll i=1; i<=n; i++){
		edge.pb({ps_cost[i], i, 0});
	}

	sort(edge.begin(), edge.end());

	dsu g(n+1);

	ll total_cost=0;
	vector<ll> ps_list;
	vector<pair<ll, ll>> join;

	for(ll i=0; i<edge.size(); i++){
		ll cost = edge[i][0];
		ll u = edge[i][1];
		ll v = edge[i][2];

		if(g.get(u) != g.get(v)){
			total_cost += cost;
			g.union_set(u, v);
			if(v==0){
				ps_list.pb(u);
			}
			else{
				join.pb({u, v});
			}
		}
	}
	cout<<total_cost<<endl;
	cout<<ps_list.size()<<endl;
	for(auto x:ps_list){cout<<x<<" ";}
	cout<<endl;
	cout<<join.size()<<endl;
	for(auto x:join){
		cout<<x.fi<<" "<<x.si<<endl;
	}
}