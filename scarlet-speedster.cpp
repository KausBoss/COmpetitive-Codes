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
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int row[4]={0, 0, 1, -1};
	int col[4]={1, -1, 0, 0};
	int t;
	cin>>t;
	while(t--){
		int n, m, x, y;
		cin>>n>>m>>x>>y;
		vector<vector<int>> grid(n, vector<int>(m));
		NF(grid, n, m);
		vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
		dp[0][0]=0;
		queue<pair<int,int>> q;
		q.push({0,0});
		while(!q.empty()){
			pair<int,int> node = q.front();
			q.pop();
			//cout<<node.fi<<" "<<node.si<<endl;
			for(int i=0; i<4; i++){
				int ni= node.fi + row[i];
				int nj= node.si + col[i];
				int cost;
				if(ni>=0 && ni<n && nj>=0 && nj<m){
					cost = (abs(grid[node.fi][node.si]-grid[ni][nj])%2==1) ? x : 0;
				}
				else{continue; }
				if(dp[ni][nj] > dp[node.fi][node.si] + cost){
					dp[ni][nj] = dp[node.fi][node.si] + cost;
					q.push({ni,nj});
				}
			}
		}
		// cout<<"here"<<endl;
		int flash = dp[n-1][m-1];
		dp = vector<vector<int>>(n, vector<int>(m, INT_MAX));
		dp[0][0]=0;
		q.push({0,0});
		while(!q.empty()){
			pair<int,int> node = q.front();
			q.pop();
			for(int i=0; i<4; i++){
				int ni= node.fi + row[i];
				int nj= node.si + col[i];
				int cost;
				if(ni>=0 && ni<n && nj>=0 && nj<m){
					cost = (abs(grid[node.fi][node.si]-grid[ni][nj])%2==0) ? y : 0;
				}
				else{continue; }
				if(dp[ni][nj] > dp[node.fi][node.si] + cost){
					dp[ni][nj] = dp[node.fi][node.si] + cost;
					q.push({ni,nj});
				}
			}
		}
		if(flash < dp[n-1][m-1]){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}