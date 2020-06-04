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
ll n;

template<typename T>
class graph{
	unordered_map<T, list<T>> m;
	pair<bool, ll> dfs_bhai(T node, unordered_map<T, bool> &visited, T dest){
		//base case for checking bhai
		visited[node]=1;
		if(node == dest){
			return {0, 0};
		}

		pair<bool, ll> res(true, 1);

		for(auto child:m[node]){
			if(!visited[child]){
				pair<bool, ll> bhai = dfs_bhai(child, visited, dest);
				if(bhai.fi){
					res.si += bhai.si;
				}
				else{
					res.fi=false;
					break;
				}
			}
		}
		return res;
	}
public:
	void addEdge(T a, T b, bool bidir=true){
		m[a].pb(b);
		if(bidir){
			m[b].pb(a);
		}
	}
	ll sage(T node, T dest){
		unordered_map<T, bool> visited;
		visited[node]=1;
		
		ll sage=0;

		for(auto child:m[node]){
			if(!visited[child]){
				pair<bool, ll> bhai = dfs_bhai(child, visited, dest);
				if(bhai.fi){
					sage += bhai.si;
				}
			}
		}
		return sage;
	}
	ll ShortestPathBFS(T src, T dest){
		map<T, int> visited;
		queue<pair<T, int>> q;

		q.push(mp(src, 0));
		visited[src] = 1;

		while(!q.empty()){
			pair<T,int> node = q.front();
			//cout<<node<<endl;
			q.pop();

			for(T x:m[node.first]){
				if(x == dest){
					return node.si + 1;
				}
				if(!visited.count(x)){
					q.push(mp(x, node.second + 1));
					visited[x]=1;//marking the neighbou as visted
				}
			}
		}
		return 0;
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		ll m, a, b;
		cin>>n>>m>>a>>b;
		graph<ll> g;
		for(ll i=0; i<m; i++){
			ll x, y;
			cin>>x>>y;
			g.addEdge(x, y);
		}
		ll aside = g.sage(a, b);
		ll dist = g.ShortestPathBFS(a, b);
		cout<<aside*(n- dist -1 - aside)<<endl;
	}
}