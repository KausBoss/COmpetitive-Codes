/*

*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
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
const int inf = 1e5+5;
const int mod = 1e9+7;

class graph{
	ll v;
	list<pii> *l;
public:
	graph(ll V){
		v =V;
		l = new list<pii>[V];
	}
	void addEdge(ll u, ll v, ll d){
		l[u].pb({v, d});
		l[v].pb({u, d});
	}

	ll FindMin(unordered_map<ll, bool> &visited, unordered_map<ll, ll> weight, ll v){
		ll minVertex=-1;
		for(ll i=0; i<v; i++){
			if(!visited[i] && minVertex == -1 || weight[minVertex > weight[i]]){
				minVertex = i;
			}
		}
		return minVertex;
	}

	void prims(){
		unordered_map<ll , bool> visited;
		unordered_map<ll, ll> parent;
		unordered_map <ll, ll> weight;

		for(ll i=0; i<v; i++){
			visited[i]=0;
			weight[i]=inf;
		}

		parent[0]=-1;
		weight[0]=0;

		for(ll i=0; i<v-1; i++){
			ll minVertex = FindMin(visited, weight, v);
			visited[minVertex] =true;
			for(auto child:l[minVertex]){
				if(!visited[child.fi]){
					if(weight[child.fi] > child.si){
						weight[child.fi] = child.si;
						parent[child.fi] = minVertex;
					}
				}
			}
		}

		for(ll i=1; i<v; i++){
			cout<<i<<" is connected to "<<parent[i]<<" with weight "<<weight[i]<<endl;
		}
	}
};

ll n, m;

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>m;

	graph g(n+1);

	for(ll i=0; i<n; i++){
		ll u, v, w;
		v--;u--;
		cin>>u>>v>>w;
		g.addEdge(u, v, w);
	}
	g.prims();
	return 0;
}

7 8
1 2 1
1 3 8
2 4 2
4 3 3
2 5 2
5 6 1
5 7 6
6 7 2
