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
	//helper function to recursively find cycle
	bool helper_dfs_cycle(T node, unordered_map<T, bool> &visited, unordered_map<T, bool> &instack){
		// mark the current node in stack and visited
		instack[node] = 1;
		visited[node] = 1;

		//iterating on the children of the current node
		//and calling the helper recursively on them
		for(auto child:m[node]){
			//recursively calling helper and checking if the 
			//child is already present in stack or not
			if(!visited[child] && helper_dfs_cycle(child, visited, instack) || instack[child]){
				return true;
			}
		}

		//marking the current node absent in instack
		instack[node] = false;
		return false;
	}

public:
	void addEdge(T a, T b, bool bidir=false){
		m[a].pb(b);
		if(bidir){
			m[b].pb(a);
		}
	}
	bool isCycle_dfs(){
		//the idea is that, if no cycle is present then a node can not be present
		//in the call stack twice in dfs algo
		//hence we explixity maintain a map instack which stores the node
		//currently in call stack
		unordered_map<T, bool> visited, instack;

		for(auto i:m){
			T node = i.fi;
			if(!visited[node]){
				//checking all disconnected components for cycle
				bool check = helper_dfs_cycle(node, visited, instack);
				if(check){
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
	cout<<g.isCycle_dfs();
}