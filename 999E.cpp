/*
we first dfs from the src node to see which all nodes are already connected
to the source. We dont need to do anything aboyut those nodes.
for rest nodes we find out which node has most connected components to it
and store this information in a priority queue.
for each unconnected node to the src we find the one with max connections,
connect it to the src node.
through this we get the optimal solution
we have used bitset instead of map for temp2 variable to avoid TLE
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
const int nax = 5e3;
const int mod = 1e9+7;

template<typename T>
class graph{
	unordered_map<T, list<T>> m;
	void dfs(T node, unordered_map<T, bool> &visited){
		visited[node]=true;

		for(auto child:m[node]){
			if(!visited[child]){
				dfs(child, visited);
			}
		}
		return;
	}
	int dfs_count(T node, bitset<nax+1> &visited){
		int cnt=1;
		visited[node]=true;

		for(auto child:m[node]){
			if(!visited[child]){
				cnt += dfs_count(child, visited);
			}
		}
		return cnt;
	}

public:
	graph(int n){
		for(int i=1; i<=n; i++){
			m[i].pb(i);
		}
	}
	void addEdge(T a, T b, bool bidir=true){
		m[a].pb(b);
		if(bidir){
			m[b].pb(a);
		}
	}
	//used this auxillay func so that we dont need to make bitset false
	//again and again
	pair<int,int> aux(T node, bitset<nax+1> visited){
		pair<int,int> res(dfs_count(node, visited), node);
		return res;
	}
	int ct(T src){
		unordered_map<T, bool> visited;
		for(auto x:m){ visited[x.fi]=false;}
		bitset<nax+1> temp2;

		dfs(src, visited);
		priority_queue<pair<int,int>> pq;
		for(auto x:m){
			if(!visited[x.fi]){
				pq.push(aux(x.fi, temp2));	
			}
		}

		int ans=0;
		while(!pq.empty()){
			pair<int, int> tp = pq.top();
			pq.pop();
			if(!visited[tp.si]){
				ans++;
				dfs(tp.si, visited);
			}
		}
		return ans;
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n, m, s;
	cin>>n>>m>>s;
	graph<int> g(n);

	for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		g.addEdge(x, y, 0);
	}

	cout<<g.ct(s);
}