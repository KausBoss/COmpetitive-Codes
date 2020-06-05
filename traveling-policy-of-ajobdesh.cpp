/*
link: https://toph.co/p/traveling-policy-of-ajobdesh
using the concept of graph transpose
to find the shortest path from every node to the captital can be done optimally
by reversive every edge of the graph and then using bfs toh find SSSP for every node
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
	int t;
	cin>>t;
	for(int tt=1; tt<=t; tt++){
		cout<<"Case "<<tt<<":\n";
		ll n, r, c, qt;
		cin>>n>>r>>c>>qt;
		vector<vector<ll>> g(n);
		vector<vector<ll>> tg(n);//reversed graph
		vector<ll> dis(n, INT_MAX);
		vector<ll> Tdis(n, INT_MAX);//to store reversed distance

		for(ll i=0; i<r; i++){
			ll x, y;
			cin>>x>>y;
			g[x].pb(y);
			tg[y].pb(x);//reversed edge
		}

		// applying bfs for given graph from the capital
		bitset <10000> visited;
		queue<ll> q;
		q.push(c);
		visited[c]=1;
		dis[c]=0;

		while(!q.empty()){
			ll node = q.front();
			q.pop();
			for(auto child:g[node]){
				if(!visited[child]){
					dis[child] = dis[node]+1;
					visited[child]=1;
					q.push(child);
				}
			}
		}

		//applying bfs for the reversed graph from the capital
		visited.reset();
		q.push(c);
		visited[c]=1;
		Tdis[c]=0;

		while(!q.empty()){
			ll node = q.front();
			q.pop();
			for(auto child:tg[node]){
				if(!visited[child]){
					Tdis[child] = Tdis[node]+1;
					visited[child]=1;
					q.push(child);
				}
			}
		}
		while(qt--){
			ll src, dest;
			cin>>src>>dest;
			ll to_cap = Tdis[src];
			ll from_cap = dis[dest];
			if(to_cap == INT_MAX || from_cap == INT_MAX){
				cout<<"Not possible to go from "<<src<<" to "<<dest<<".\n";
			}
			else{
				cout<<"The shortest distance from "<<src<<" to "<<dest<<" is "<<to_cap+from_cap<<".\n";
			}
		}
		g.clear(); tg.clear();
	}
}