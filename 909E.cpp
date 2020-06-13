/*

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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin>>n>>m;
	bitset<(int)1e5> type;
	for(int i=0; i<n; i++){
		int t;
		cin>>t;
		type[i] = t;
	}
	vector<int> indegree(n, 0);
	vector<vector<int>> g(n);
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		indegree[v]++;// to store indegree of all nodes
	}
	queue<int> q;
	int ans=0;
	vector<int> func(n, -1);//to store the number of coprocessor call needed for node i 
	for(ll i=0; i<n; i++){
		if(indegree[i]==0){
			q.push(i);
			func[i] = (type[i]) ? 1 : 0;
			ans = max(func[i], ans);
		}
	}
	// P(indegree, n);
	while(!q.empty()){
		ll node = q.front();
		q.pop();
		for(auto child:g[node]){
			// cout<<node<<" "<<child<<endl;
			indegree[child]--;
			ll adder = (type[child]==1&&type[node]==0) ? 1: 0;
			if(func[child] < func[node] + adder){
				func[child] = func[node] + adder;
				ans = max(func[child], ans);
			}
			if(indegree[child]==0){
				q.push(child);//pushing if indegree becomes zero
			}
		}
	}
	cout<<ans;
}