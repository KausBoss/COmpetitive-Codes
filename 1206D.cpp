/*
The most important thing in this task is to notice that if any bit is contained at 
least 3 numbers, then they will form a cycle of length 3, and the answer is 3.

Suppose now that each bit is in no more than two numbers. It follows that each bit 
can be shared by at most one pair of numbers. From here we get that in the graph 
there are no more than 60 edges. Then in it you can find the shortest cycle 
in O(m2): for each edge between the vertices u and v we will try to remove it and 
find the shortest distance between the vertices u, v in the resulting graph. 
If each time u and v turned out to be in different components, then there is no 
cycle in the graph, otherwise its length is 1 + the minimal of the distances found.

Asymptotics O(n log1018+602).

remove all 0 from input stream
check if any bit has more than 2 numbers
yes->ans=3
no-> find shortest cycel by bfs on every node
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

template<typename T>
class graph{
	unordered_map<T, list<T>> m;
public:
	void addEdge(T a, T b, bool bidir=true){
		m[a].pb(b);
		if(bidir){
			m[b].pb(a);
		}
	}

	void shortcycle(){
		ll cyc = INT_MAX;
		for(auto node:m){
			unordered_map<T, ll> dist;
			unordered_map<T, T> parent;

			dist[node.fi] = 0;
			parent[node.fi] = node.fi;

			queue<T> q;
			q.push(node.fi);

			while(!q.empty()){
				T p = q.front();
				q.pop();

				for(auto child:m[p]){
					if(dist.count(child) == 0){
						dist[child] = dist[p] + 1;
						parent[child] = p;
						q.push(child);
					}
					else if(parent[p] != child && parent[child] != p){
						cyc = min(cyc, dist[p] + dist[child] + 1);
					}
				}
			}
			dist.clear();
			parent.clear();
		}
		if(cyc == INT_MAX){
			cout<<-1;
			return;
		}
		cout<<cyc;
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n;
	vector<ll> bit(61, 0);
	vector<ll> node;
	ll mx = 0;
	cin>>n;
	for(ll i=0; i<n; i++){
		ll temp;
		cin>>temp;
		if(temp){
			node.pb(temp);
			ll pos=0;
			while(temp){
				if(temp&1){
					bit[pos]++;
					mx = max(bit[pos], mx);
				}
				pos++;
				temp = temp>>1;
			}
		}
	}
	if(mx > 2){
		cout<<3;
		return 0;
	}
	graph<ll> g;
	
	for(ll i=0; i<node.size()-1; i++){
		for(ll j=i+1; j<node.size(); j++){
			if(node[i]&node[j]){
				g.addEdge(node[i], node[j]);
			}
		}
	}
	g.shortcycle();
}