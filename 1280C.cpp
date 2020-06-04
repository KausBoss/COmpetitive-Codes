//link:https://codeforces.com/problemset/problem/1280/C
//to maximize the answer we must use every edge the max number of times
//for that to happen we will calculate number of subnodes on right and left of 
//each eadge. The min value of right and left will give us the maximum possible
//usage of an edge. we will calculate this using dfs

//to calculate the minimum usage, we will use the ans of the max usage 
//let n denote the max usage of edge (ab), then, when we use the edge min number
//of times, we create pair within left subtree and within right subtree
//for that to happen we take mod2 of min(left_size, right_size)
//this gives us the min usage of the edge (ab)

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
ll n;


template<typename T>
class graph{
	unordered_map<T, list<pair<T, ll>>> m;
	//using dfs to find nodes in subtree on one side of the edge
	ll maxval_dfs(T node, unordered_map<T, bool> &visited, ll *cnt, ll &ans){
		visited[node]=1;

		cnt[node]=1;

		for(auto child:m[node]){

			ll dx= child.si;

			if(!visited[child.fi]){
				cnt[node] += maxval_dfs(child.fi, visited, cnt, ans);
				//NOTE: for edge btw node and child
				ll right = cnt[child.fi];
				ll left = n - right;
				ans += min(left, right)*dx;
			}
		}
		return cnt[node];
	}

	ll minval_dfs(T node, unordered_map<T, bool> &visited, ll *cnt, ll &ans){
		visited[node]=1;

		cnt[node]=1;

		for(auto child:m[node]){

			ll dx= child.si;

			if(!visited[child.fi]){
				cnt[node] += minval_dfs(child.fi, visited, cnt, ans);
				ll right = (cnt[child.fi])%2;
				ll left = (n- right)%2;
				ans += min(left, right)*dx;
			}
		}
		return cnt[node];
	}
public:
	void AddEdge(T a, T b, ll cost,bool bidir=true){
		m[a].pb(mp(b, cost));
		if(bidir){
			m[b].pb(mp(a, cost));
		}
	}

	ll max_val(){
		unordered_map<T, bool> visited;
		ll *cnt = new ll[n+1]; //stores the number of nodes on one side of an edge

		for(ll i=1; i<=n; i++){
			cnt[i]=0;
		}
		ll ans=0;
		maxval_dfs(1, visited, cnt, ans);
		return ans;
	}
	ll min_val(){
		unordered_map<T, bool> visited;
		ll *cnt = new ll[n+1]; //stores the number of nodes on one side of an edge

		for(ll i=1; i<=n; i++){
			cnt[i]=0;
		}
		ll ans=0;
		minval_dfs(1, visited, cnt, ans);
		return ans;
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
		ll k;
		cin>>k;
		n = 2*k;
		graph<ll> g;
		for(ll i=0;i<n-1; i++){
			ll a, b, cost;
			cin>>a>>b>>cost;
			g.AddEdge(a, b, cost);
		}
		cout<<g.min_val()<<" "<<g.max_val()<<"\n";
	}
}