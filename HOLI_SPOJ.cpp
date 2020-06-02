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
// idead is to maximize use of every edge.
// an edge can be used a max  2*min(number of nodes in left, number of nodes in right)
// this is becuase a one traveller from left will occupy on house on right and vice versa
// hence distace will be dist_of_edge*2*min(number of nodes in left, number of nodes in right)

ll n;

template<typename T>
class graph{
	unordered_map<T, list<pair<T,ll> >> h;
public:
	void addEdge(T u, T v, int dist){
		h[u].pb({v,dist});
		h[v].pb({u, dist});
	}
	// using dfs to count the number of nodes on each side of edge
	ll dfs(T node, unordered_map<T, bool> &visited, ll *cnt, ll &ans){
		visited[node]=1;
		//counting the current node in the count
		cnt[node] =1;

		for(auto child: h[node]){
			//dx is the weight of the edge
			ll dx = child.si;
			if(!visited[child.fi]){
				//counting all nodes on the side of the current node in cnt[node] using dfs
				cnt[node] += dfs(child.fi, visited, cnt, ans);
				ll right = cnt[child.fi];
				// the other side will have n- right number of nodes
				ll left = n - right;
				ans += 2*min(left, right)*dx;
			}
		}
		return cnt[node];
	}
	ll holiday(){
		unordered_map<T, bool> visited;
		//cnt[node] stores the number of nodes on the side of node including itself
		ll *cnt = new ll[n];

		for(ll i=0; i<n; i++){
			cnt[i] = 0;
		}
		ll ans=0;
		dfs(0, visited, cnt, ans);
		return ans;
	}
	
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll t,counter=1;
	cin>>t;
	while(t--){
		graph<ll> g;
		cin>>n;
		for(ll i = 1 ; i<n ; i++){
			ll x,y,z;
			cin>>x>>y>>z;
			g.addEdge(x-1,y-1,z);
		}
		cout<<"Case #"<<counter<<": "<<g.holiday()<<endl;
		counter++;
	}

	return 0;
}