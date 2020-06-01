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

vector<int> val;

class Graph{
	map<int, list<int>> m;
public:
	void AddEdge(int x, int y){
		m[x].pb(y);
		m[y].pb(x);
	}

	void ShortestPathBFS(int src, int dest, int n){
		map<int, bool> visited;
		queue<int> q;
		int pred[n+1];
		pred[src] = -1;

		q.push(src);
		visited[src]=1;
		bool signal = false;
		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(int x:m[node]){
				if(x == dest){
					pred[x] = node;
					signal = 1;
					break;
				}
				if(!visited.count(x)){
					q.push(x);
					pred[x] = node;
					visited[x]=1;//marking the neighbou as visted
				}
			}
			if(signal){break;}
		}

		vector<int> liss;
		int r=dest;
		liss.pb(val[r-1]);
		while (pred[r] != -1) {  
        	r = pred[r]; 
        	liss.pb(val[r-1]);
    	}
		sort(liss.begin(), liss.end());
		int mini=INT_MAX;
		for(int i=0; i<liss.size()-1; i++){
			mini= min(mini, liss[i+1] - liss[i]);
		}
		cout<<mini<<"\n";
	}
};


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		val.resize(n);
		F(val ,n);

		Graph g;
		for(int i=0; i<(n-1); i++){
			int u, v;
			cin>>u>>v;
			g.AddEdge(u, v);
		}

		for(int i=0; i<q; i++){
			int src, dest;
			cin>>src>>dest;
			g.ShortestPathBFS(src, dest, n);
		}
	}
}