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
const int nax = 1e5+2;
const int mod = 1e9+7;

ll cost[nax][102];
ll a[nax];//konsi state konsa product banati hai
vector<ll> g[nax]; //adjecency
ll n, m, k, s;

void solve(){
	for(ll product=1; product<=k ; product++){
		for(ll i=1; i<=n; i++){
			if(a[i] == product){
				cost[i][product] = 0,q.push(i);
			}
		}

		while(!q.empty()){
			ll node = q.front();
			q.pop();
			for(auto child:g[node]){
				if(cost[child][product] == -1){
					cost[child][product] = cost[node][product] + 1;
				}
			}
		}

	}
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>m>>k>>s;
	F1(a, n);
	for(ll i=0; i<m; i++){
		ll u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}

	memset(cost, -1, sizeof cost); // initializing the cost matrix


}