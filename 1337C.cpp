/*
direct greedy will give the wrong asnwer.
we will find the distance of each node from the root using bfs
then we will subtract the number of subNodes below it from the height
that will be the maximum effective contribution that node can make
select the max k nodes from the effort array
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

vector<int> effort;

template<typename T>
class graph{
	unordered_map<T, list<T>> m;

	int dfs_helper(T node, unordered_map<T, bool> &visited){
		visited[node]=true;
		int subNode=0;
		for(auto child:m[node]){
			if(!visited[child]){
				subNode += dfs_helper(child, visited);
			}
		}
		effort[node] -= subNode;
		return subNode+1;
	}
public:
	void addEdge(T a, T b, bool bidir=true){
		m[a].pb(b);
		if(bidir){
			m[b].pb(a);
		}
	}
	void height(T src){
		map<T, int> visited;
		queue<pair<T, int>> q;

		q.push(mp(src, 0));
		visited[src] = 1;

		while(!q.empty()){
			pair<T,int> node = q.front();
			q.pop();

			for(T x:m[node.first]){
				if(!visited.count(x)){
					q.push(mp(x, node.si + 1));
					effort[x] = node.si + 1;
					visited[x]=1;
				}
			}
		}
		return;
	}
	void dfs(){
		unordered_map<T, bool> visited;
		for(auto x:m){visited[x.fi]=false;}

		dfs_helper(0, visited);
	}
};



int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin>>n>>k;
	effort = vector<int>(n, 0);
	graph<int> g;
	for(int i=0; i<n-1; i++){
		int x, y;
		cin>>x>>y;
		x--;y--;
		g.addEdge(x, y);
	}
	g.height(0);
	g.dfs();
	sort(effort.begin(), effort.end());
	ll ans=0;
	for(int i=effort.size()-1; i>=(n-k); i--){
		ans += effort[i];
	}
	cout<<ans;
}