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

class Graph1{
	int v;
	list <int> *l;
public:
	Graph1(int v){
		this->v= v;
		l = new list<int>[v];
	}
	void AddEdge(int x, int y){
		l[x].pb(y);
		l[y].pb(x);
	}
	void PrintGraph(){
		for (int i=0; i<v; i++){
			cout<<"Vertex "<< i <<"-> ";
			for(int nbr:l[i]){
				cout<<nbr<<", ";
			}
			cout<<endl;
		}
	}
};

class Graph2{
	int v;
	unordered_map<string, list<pair<string, int>>> m;
public:
	Graph2(int v){
		this->v = v;
	}
	void AddEdge(string a, string b, bool bidir, int cost){
		m[a].pb(mp(b, cost));
		if(bidir){
			m[b].pb(mp(a, cost));
		}
	}
	void PrintGraph(){
		for(auto x: m){
			cout<<x.first<<"->";
			for(auto y:x.second){
				cout<<"("<<y.first<<","<<y.second<<"), ";
			}
			cout<<endl;
		}
	}
};

template<typename T>
class Graph{
	map<T, list<T>> m;
public:
	void AddEdge(T x, T y){
		m[x].pb(y);
		m[y].pb(x);
	}

	void bfs(T src){
		map<T, int> visited;
		queue<T> q;

		q.push(src);
		visited[src] = 1;

		while(!q.empty()){
			T node = q.front();
			cout<<node<<endl;
			q.pop();

			for(T x:m[node]){
				if(!visited.count(x)){
					q.push(x);
					visited[x]=1;//marking the neighbou as visted
				}
			}
		}
	}
	void ShortestPathBFS(T src, T dest){
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
					cout<<node.second+1<<endl;
					return;
				}
				if(!visited.count(x)){
					q.push(mp(x, node.second + 1));
					visited[x]=1;//marking the neighbou as visted
				}
			}
		}
		cout<<"Destination not found "<<endl;
		return;
	}
	void dfs_helper(T src, map<T, bool> &visited){
		//recursive function
		cout<<src<<" ";
		visited[src] = true; // marking the current node as visited
		//go to all neighbour of that node
		for(T nbr: m[src]){
			if(!visited[nbr]){
				dfs_helper(nbr, visited);
			}
		}
	}

	void dfs (T src){
		map<T, bool> visited;
		for(auto node:m){
			visited[node.fi]=false;
		}
		//calling the helper fucntion
		dfs_helper(src, visited);
	}
	void ComponentDFS(){
		map<T, bool> visited;
		for(auto node:m){
			visited[node.fi]=false;
		}
		//calling the helper fucntion
		int cnt=1;
		for(auto node:m){
			if(!visited[node.fi]){
				cout<<"Component "<<cnt<<" -> ";
				dfs_helper(node.fi, visited);
				cout<<endl;
			}
		}

	}
};

template<typename T>
class GraphSnL{
	map<T, list<T>> m;
public:
	void AddEdge(T x, T y){
		m[x].pb(y);
		//m[y].pb(x);
	}

	void bfs(T src){
		map<T, int> visited;
		queue<T> q;

		q.push(src);
		visited[src] = 1;

		while(!q.empty()){
			T node = q.front();
			cout<<node<<endl;
			q.pop();

			for(T x:m[node]){
				if(!visited.count(x)){
					q.push(x);
					visited[x]=1;//marking the neighbou as visted
				}
			}
		}
	}
	void ShortestPathBFS(T src, T dest){
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
					cout<<node.second+1<<endl;
					return;
				}
				if(!visited.count(x)){
					q.push(mp(x, node.second + 1));
					visited[x]=1;//marking the neighbou as visted
				}
			}
		}
		cout<<"Destination not found "<<endl;
		return;
	}
	void PrintGraph(){
		for(auto x: m){
			cout<<x.first<<"->";
			for(auto y:x.second){
				cout<<y<<" ";
			}
			cout<<endl;
		}
	}
};

template<typename T>
class Graph3{
	map<T, list<T>> m;
public:
	void AddEdge(T x, T y){
		m[x].pb(y);
		//m[y].pb(x);
	}

	void dfs_helper(T src, map<T, bool> &visited){
		//recursive function
		cout<<src<<" ";
		visited[src] = true; // marking the current node as visited
		//go to all neighbour of that node
		for(T nbr: m[src]){
			if(!visited[nbr]){
				dfs_helper(nbr, visited);
			}
		}
	}

	void ComponentDFS(){
		map<T, bool> visited;
		for(auto node:m){
			visited[node.fi]=false;
		}
		//calling the helper fucntion
		int cnt=1;
		for(auto node:m){
			if(!visited[node.fi]){
				cout<<"Component "<<cnt<<" -> ";
				dfs_helper(node.fi, visited);
				cout<<endl;
			}
		}

	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

 	// Graph<int> g;
	// g.AddEdge(0, 1);
	// g.AddEdge(1, 2);
	// g.AddEdge(2, 3);
	// g.AddEdge(0, 3);
	// g.AddEdge(0, 4);

	// g.AddEdge(5, 6);
	// g.AddEdge(6, 7);

	// g.AddEdge(8, 9);
	// g.AddEdge(9, 10);

	// g.AddEdge(11, 12);
	// g.ComponentDFS();

	//Graph<int> g;
	// g.AddEdge(1, 2);
	// g.AddEdge(1, 0);
	// g.AddEdge(2, 3);
	// g.AddEdge(3, 0);
	// g.AddEdge(3, 4);
	// g.AddEdge(4, 5);
	// g.dfs(1);

	// vector<int> jump(101, 0);

	// jump[2]=23;
	// jump[8]=12;
	// jump[17]=93;
	// jump[29]=54;
	// jump[32]=51;
	// jump[39]=80;
	// jump[62]=78;
	// jump[70]=89;
	// jump[75]=96;

	// jump[41]=20;
	// jump[31]=14;
	// jump[59]=37;
	// jump[67]=50;
	// jump[92]=76;
	// jump[83]=80;
	// jump[99]=4;

	// GraphSnL<int> game;

	// for(int i=1; i<100; i++){
	// 	if(jump[i]==0){
	// 		for(int j=1; j<=6; j++){
	// 			if(jump[i+j]==0){
	// 				game.AddEdge(i, i+j);
	// 			}
	// 			else{
	// 				game.AddEdge(i, jump[i+j]);
	// 			}
	// 		}
	// 	}
	// }

	// game.ShortestPathBFS(1, 100);

	// Graph<int> g;
	// g.AddEdge(1, 2);
	// g.AddEdge(1, 0);
	// g.AddEdge(2, 3);
	// g.AddEdge(3, 0);
	// g.AddEdge(3, 4);
	// g.AddEdge(4, 5);
	// //g.bfs(1);
	// g.ShortestPathBFS(1, 5);

	// Graph g<string>;
	// g.AddEdge("A", "B", true, 20);
	// g.AddEdge("A", "C", true,10);
	// g.AddEdge("A", "D", false,50);
	// g.AddEdge("B", "D", true,30);
	// g.AddEdge("C", "D", true,40);
	// g.PrintGraph();

}