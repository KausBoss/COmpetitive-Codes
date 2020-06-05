/*
D. Valid BFS?
calculate the height and parent of each node using bfs
and use this condition over the given bfs sequence
height[given_bfs[i-1]] > height[given_bfs[i]] ||(height[given_bfs[i-1]] == height[given_bfs[i]] && id[parent[given_bfs[i-1]]] > id[parent[given_bfs[i]]] ))
height of the i+1th node should always be greater or equal to the height of ith node
also if heights are equal the index of their parents in the given bfs sequence
must be same or index of parent of i+1th node should be greater the parent of ith node
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

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n;
	cin>>n;
	map<ll, list<ll>> m;
	vector<ll> given_bfs(n);
	for(int i=0; i<n-1; i++){
		ll x, y;
		cin>>x>>y;
		m[x].pb(y);
		m[y].pb(x);
	}
	F(given_bfs, n);
	queue<ll> q;
	vector<ll> id(n+1);
	for(int i=0; i<n; i++){
		id[given_bfs[i]] = i;
	}
	map<ll, ll> height;
	map<ll, ll> parent;
	parent[1]=-1;
	height[1]=0;
	q.push(1ll);

	while(!q.empty()){
		ll node = q.front();
		q.pop();

		for(auto child:m[node]){
			if(height.count(child) == 0){
				height[child] = height[node]+1;
				parent[child] = node;
				q.push(child);
			}
		}
	}

	for(int i=1; i<n; i++){
		if(height[given_bfs[i-1]] > height[given_bfs[i]] ||(height[given_bfs[i-1]] == height[given_bfs[i]] && id[parent[given_bfs[i-1]]] > id[parent[given_bfs[i]]] )){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}