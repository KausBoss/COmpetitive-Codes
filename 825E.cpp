/*
topological sort
transpose of graph
sort nodes according to outdegree and index using priority queue
update the outdegree at every itreation

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

struct custom{
	bool operator()(const pair<ll,ll> &a, const pair<ll,ll> &b){
		if(a.fi == b.fi){
			return a.si < b.si;
		}
		return a.fi > b.fi;
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
	vector<vector<ll>> g(n), tg(n);
	for(ll i=0; i<m; i++){
		ll u, v;
		cin>>u>>v;
		u--; v--;
		g[u].pb(v);
		tg[v].pb(u);//to store the nodes which are indgree to i
	}
	vector<ll> outdeg(n);
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, custom> q;//outdegree of i is number of nodes i can go from ith node
	for(ll i=0; i<n; i++){
		q.push({g[i].size(), i});
		outdeg[i] = g[i].size();
	}
	vector<ll> permute(n);
	vector<bool> visited(n, 0);
	ll val = n;
	while(!q.empty()){
		auto p = q.top();
		q.pop();
		if(visited[p.si]==0){
			// cout<<p.fi<<" "<<p.si<<endl;
			visited[p.si] = 1;
			permute[p.si] = val--;
			for(auto child:tg[p.si]){
				outdeg[child]--;
				q.push({outdeg[child], child});
			}
		}
	}

	P(permute, n);
}