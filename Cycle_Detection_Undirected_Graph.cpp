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

	bool cycle_dfs_helper(T node, unordered_map<T, bool> &visited, T parent){
		//mark the current node as visited
		visited[node] = true;

		//iterate over all children of the current node
		for(auto child:m[node]){
			//if the child is not visited check for cycle recursively
			if(!visited[child]){
				bool check = cycle_dfs_helper(child, visited, node);
				if(check){
					return true;
				}
			}
			else if(child != parent){// if the child is visited, it must be the parent node
				return true;
			}
		}
		return false;
	}
public:
	void addEdge(T a, T b, bool bidir=true){
		m[a].pb(b);
		if(bidir){
			m[b].pb(a);
		}
	}

	bool cycle_dfs(){
		//the idea is to keep a track of the parent of the node we are checking for
		//if there is a child of the current node that is already visited and its
		//not the parent of the current node, it means a cycle exists


		//map visited will store the nodes which are already visited
		unordered_map<T, bool> visited;

		for(auto i:m){
			if(!visited[i.fi]){
				bool check = cycle_dfs_helper(i.fi, visited, i.fi);
				if(check){
					return true;
				}
			}
		}
		return false;
	}
	//we will need a src node to check for cycle using bfs
	//we will keep track of parent of each node, if child of current node
	//is already visited and it is not the parent of the current node, cycle exists
	bool cycle_bfs(T src){
		//we will maintain a visited and a parent map
		unordered_map<T, bool> visited;
		unordered_map<T, T> parent;

		//marking the parent of src as itself
		parent[src] = src;
		//marking src as visited
		visited[src] = 1;
		queue<T> q;
		q.push(src);

		while(!q.empty()){
			T node = q.front();
			q.pop();

			//iterating the children of current node
			for(auto child:m[node]){
				//if child is not visited, pushing it into queue, and marking it as visited
				if(!visited[child]){
					visited[child] = 1;
					parent[child] = node;
					q.push(child);
				}
				//if a node is visited, it must be parent of the current node,
				//else cycle exists
				else if(parent[node] != child){
					return true;
				}
			}
		}
		return false;
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
	cout<<g.cycle_dfs()<<endl;
	cout<<g.cycle_bfs("a");
}