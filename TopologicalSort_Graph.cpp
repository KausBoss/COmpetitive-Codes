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

	void tps_dfs_helper(T node, unordered_map<T, bool> &visited, list<T> &l){
		// marking the current node as visited
		visited[node] = true;

		//children of the current node
		for(auto child:m[node]){
			if(visited.count(child) == 0){
				//recursively calling for unvisited children
				tps_dfs_helper(child, visited, l);
			}
		}
		//pushing at the end from the front in the queue
		l.push_front(node);
		return;
	}
public:
	void addEdge(T a, T b, bool bidir=false){
		m[a].pb(b);
		//for bidirectional edge
		if(bidir){
			m[b].pb(a);
		}
	}
	void Topological_dfs(){
		//visited map keeps track of nodes which we have already visited
		//to avoid revisiting
		unordered_map<T, bool> visited;
		//ans will be stored in list l by push_front
		list<T> l;

		for(auto node:m){
			//calling helper function for unvisited node
			if(visited.count(node.fi) == 0){
				tps_dfs_helper(node.fi, visited, l);
			}
		}

		//printing
		for(auto x:l){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	void tps_bfs(){
		//in bfs topological sort, we maintain an indegree map to
		//store the number of parent a node has
		// the staring node will have indegree = 0
		unordered_map<T, ll> indegree;

		//loop to initialize the indegree of each node
		for(auto node:m){
			//iterating the children of node and incrementing 
			//their indegree by 1
			for(auto child:node.si){
				indegree[child]++;
			}
		}
		//now we prform iterative bfs with a queue
		queue<T> q;
		//updating the queue by pushing the
		//nodes which has indegree == 0
		for( auto i:m){
			T node = i.fi;
			if(indegree[node] == 0){
				q.push(node);
			}
		}

		while(!q.empty()){
			T node = q.front();
			q.pop();
			cout<<node <<" ";
			//decrementing the indegree of children of node by 1
			for(auto child:m[node]){
				indegree[child]--;
				//if indegree == 0, push in queue
				if(indegree[child] == 0){
					q.push(child);
				}
			}
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
	graph<string> g;
	int t;
	cin>>t;
	while(t--){
		string a, b;
		cin>>a>>b;
		g.addEdge(a, b);
	}

	g.Topological_dfs();
	g.tps_bfs();
}
/*
input:
11
english progL
math progL
progL HTML
english HTML
progL python
progL java
HTML CSS
python JS
CSS JS
java webD
JS webD
*/
