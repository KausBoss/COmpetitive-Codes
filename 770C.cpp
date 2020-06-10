/*
take transpose of the graph and them do topological sort
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
	bool dfs_helper(ll node, vector<bool> &visited, unordered_map<ll, bool> &slack, vector<ll> &topo){
		visited[node] = 1;
		slack[node] = 1;
		for(auto child:m[node]){
			if((!visited[child] && dfs_helper(child, visited, slack, topo)) || slack[child]){
				return true;
			}
		}
		slack.erase(node);
		topo.pb(node);
		return false;
	}
public:
	void addEdge(T a, T b, bool bidir=false){
		m[a].pb(b);
		if(bidir){
			m[b].pb(a);
		}
	}
	void dfs(vector<ll> special, ll n){
		vector<bool> visited(n+1, 0);
		unordered_map<ll, bool> slack;
		vector<ll> topo;
		for(auto sp:special){
			if(!visited[sp]){
				bool cycle = dfs_helper(sp, visited, slack, topo);
				if(cycle){
					cout<<-1;
					return;
				}
			}
		}
		cout<<topo.size()<<endl;
		for(auto x:topo){
			cout<<x<<" ";
		}
		return;
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n, k;
	cin>>n>>k;
	vector<ll> special(k);
	F(special, k);
	graph<ll> g;
	for(ll i=1; i<=n; i++){
		ll ct;
		cin>>ct;
		while(ct--){
			ll pt;
			cin>>pt;
			g.addEdge(i, pt);
		}
	}
	g.dfs(special, n);
}