/*
Floyd Warshall Algorithm
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
#define PPNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){if(a[i][j]>=0)cout<<" ";cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
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

	void addEdge(T a, T b, ll cost, bool bidir=false){
		m[a].pb({b, cost});
		if(bidir){
			m[b].pb({a, cost});
		}
	}

	void Floyd(){
		vector<vector<ll>> dp(v, vector<ll>(v, INT_MAX));

		for(ll i=0; i<v; i++){
			dp[i][i]=0;// distance to self will be zero
		}

		//filling the edge cost into the dist matrix
		for(auto node:m){
			for(auto child:node.si){
				dp[node.fi][child.fi] = child.si;
			}
		}
		//PPNF(dp, v, v);

		for(ll k=0; k<v; k++){
			for(ll i=0; i<v; i++){
				for(ll j=0; j<v; j++){
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}

		PPNF(dp, v, v);

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
	ll m;//number of edges
	cin>>m;
	for(int i=0; i<m; i++){
		ll u, v, w;
		cin>>u>>v>>w;
		u--;v--;
		g.addEdge(u, v, w);
	}
	g.Floyd();
}