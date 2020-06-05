/*
D. Fair 
use multi source BFS to find the min cost to provide each of the kth item
to every node. 
Then sort those cost from every node and pick the s smallest ones
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
// #define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
// #define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
// #define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
// #define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
// #define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
//#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
//#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e4+5;
const int mod = 1e9+7;


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n, mp, K, s;
	cin>>n>>mp>>K>>s;

	vector<list<ll>> m(n);
	vector<ll> which_item(n);//which node produces which item
	vector<vector<ll>> cost(n, vector<ll>(K+1, -1));//initially all -1

	for(ll i=0; i<n; i++){
		cin>>which_item[i];
	}

	for(ll i=0; i<mp; i++){
		ll x, y;
		cin>>x>>y;
		x--;y--;//0 indexed nodes
		m[x].pb(y);
		m[y].pb(x);
	}

	//multi source bfs
	queue<ll> q;

	for(ll k=1; k<=K; k++){
		//places which produce k-type item
		for(ll i=0; i<n; i++){
			if(which_item[i] == k){
				cost[i][k]=0;
				q.push(i);
			}
		}
		//multi source bfs (because our q has more than 1 src)
		while(!q.empty()){
			ll node = q.front();
			q.pop();

			for(auto child:m[node]){
				//if the cost is -1 that means no other source has reahced
				//this child before, hence current path is the shortest
				if(cost[child][k] == -1){
					cost[child][k] = cost[node][k]+1;
					q.push(child);
				}
			}
		}
	}
	//sorting to get the s minimum items
	for(int i=0; i<n; i++){
		sort(cost[i].begin(),cost[i].end());
	}

	for(ll i=0; i<n; i++){
		ll ans=0;
		//j starting from 1 because cost[~][0]==-1 for all nodes
		//as there is no product of 0 name
		for(ll j=1; j<=s; j++){
			ans += cost[i][j];
		}
		cout<<ans<<" ";
	}
}