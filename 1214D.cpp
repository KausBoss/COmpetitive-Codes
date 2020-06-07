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
	int n, m;
	cin>>n>>m;
	vector<string> s[n];
	F(s, n);
	if(s[1][0] == '#' && s[0][1]=='#'){
		cout<<0;
		return 0;
	}

	int close=0;
	int row[2] = {0,1};
	int col[2] = {1, 0};
	vector<vector<pair<int,int>>> dp(n, vector<int>(m, {-1,-1}));
	queue<pair<int,int>> q;
	if(s[0][1]!='#'){
		dp[0][1]={0,1};
		q.push({0,1});
	}
	if(s[1][0]!='#'){
		dp[1][0]={1,0};
		q.push({0,1});
	}

	while(!q.empty()){
		pair<int,int> node = q.front();
		q.pop();
		int ci = node.fi;
		int cj = node.si;
		for(int i=0; i<2; i++){
			int ni = ci + row[i];
			int nj = cj + col[i];
			if(ni>=0 &&ni<n && nj>=0 && nj<m && s[ni][nj]=='.'){
				dp[ni][nj] = 1;
				q.push({ni,nj});
			}
		}
	}

	for(int i=0;  i<n; i++){
		for(int j=0; j<m; j++){
			if(!(i==0 && j==0)){
				
			}
		}
	}
}