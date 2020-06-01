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
	unordered_map<T, list<pair<T,ll> >> h;
public:
	void addEdge(T u, T v, int dist){
		h[u].pb({v,dist});
		h[v].pb({u, dist});
	}
	ll dfs(T node, unordered_map<T, bool> &visited, ll *cnt, ll &ans){
		visited[node]=1;
		cnt[node] =1;

		for(auto child: h[node]){
			ll dx = child.si;
			if(!visited[child.fi]){
				cnt[node] += dfs(child.fi, visited, ans);
				ll right = cnt[child.fi];
				ll left = n - right;
				ans += 2*min(left, right)*dx;
			}
		}
		return cnt[node];
	}
	void holiday(){
		unordered_map<T, bool> visited;
		ll *cnt = new cnt[n];

		for(ll i=0; i<n; i++){
			cnt[i] = 0;
		}
		ll ans=0;
		dfs(0, visited, cnt, ans);
		return ans;
	}
	
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(ll i=1; i<n; i++){
			ll x, y, w;
			cin>>x>>y>>w;
			g.addEdge(x-1, y-1, w);
		}
		cout<<"Case #"<<ctr<<": "<<g.holiday()<<endl;
	}
}