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
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){if(a[i][j]>=0)cout<<" ";cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e4+5;
const int mod = 1e9+7;

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	ll row[4] = {0, 0, 1, -1};
	ll col[4] = {1, -1, 0, 0};
	ll n, m, k;
	cin>>n>>m>>k;
	
	string room[1000];
	ll dp[1000][1000];
	memset(dp, -1, sizeof(dp));

	for(int i=0; i<n; i++){
		cin>>room[i];
	}

	ll r, c, x, y;
	cin>>r>>c>>x>>y;
	r--; c--; x--; y--;
	queue<pair<ll,ll>> q;

	dp[r][c]=0;
	q.push({r, c});

	while(!q.empty()){
		pair<ll,ll> node = q.front();
		q.pop();

		for(int i=0; i<4; i++){
			ll ni = node.fi;
			ll nj = node.si;
			for(int j=1; j<=k; j++){
				ni += row[i];
				nj += col[i];
				if(!(ni>=0 && ni<n && nj>=0 && nj<m && room[ni][nj]=='.'))break;
				if(dp[ni][nj] == -1){
					if(ni == x && nj == y){
						//PNF(dp, n, m);
						cout<<dp[node.fi][node.si]+1;
						return 0;
					}
					dp[ni][nj] = dp[node.fi][node.si]+1;
					q.push({ni, nj});
				}
				}
			}
		}

	cout<<dp[x][y];
}