/*
use graph transpose to get all distance from final destination
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
	unordered_map<T, list<T>> m;
	unordered_map<T, ll> dist;
	unordered_map<T, vector<T>> next;
public:
	void addEdge(T a, T b){
		m[a].pb(b);
	}

	void rebuild(){
		ll k;
		cin>>k;
		vector<T> path(k);
		F(path, k);

		T src = path[k-1];

		queue<pair<T, ll>> q;
		q.push({src, 0});
		dist[src] = 0;

		while(!q.empty()){
			auto node = q.front();
			q.pop();

			for(auto child:m[node.fi]){
				if(dist.count(child) == 0){
					dist[child] = node.si+1;
					next[child].pb(node.fi);
					q.push({child, dist[child]});
				}
				else{
					if(dist[child] == node.si+1){
						next[child].pb(node.fi);
					}
				}
			}
		}

		int maxV=0, minV=0;
		for(int i=0; i<k-1; i++){
			if(dist[path[i]]-1 < dist[path[i+1]]){
				maxV++;
				minV++;
			}
			else if(next[path[i]].size() > 1){
				maxV++;
			}
		}
		cout<<minV<<" "<<maxV;
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n, m;
	cin>>n>>m;
	graph<ll> g;
	for(ll i=0; i<m; i++){
		ll u, v;
		cin>>u>>v;
		g.addEdge(v, u);
	}
	g.rebuild();
}