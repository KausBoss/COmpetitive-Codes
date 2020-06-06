/*
*D.Labrinth*

let (r, c) be the starting cell and (i, j) be the final cell
then number of right moves and number of left moves to reach (i, j) can be represented as-
c + right - left = j
therefore right = left + j - c
we will use this equation to find the total right and left moves
if they lie within the range of valid x(max right moves allowed) , y(max left moves allowed) we count that cell 
-> To make this a 0/1 BFS problem we will assign cost 1 to move left and 0 to rest(right, up, dowm)
that way we will be able to calculate the left moves
and subsequently we can find number of right moves

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
ll n, m, r, c, x, y;

//to store movements
ll rows[4] = {0, 0, 1, -1};
ll cols[4] = {1, -1, 0, 0};
ll cost[4] = {0, 1, 0, 0};//cost of moving left is 1, rest 0
string maze[2005]; //give maze
ll dp[2005][2005]; //to store the min number of left moves to come to cel (i, j)

bool isValid(ll x, ll y){
	return (x>=0 && x<n && y>=0 && y<m && maze[x][y]=='.');
}


void solve(){
	deque<pair<ll,ll>> q;// to store pair<row, col> of current cell
	memset(dp, -1, sizeof(dp));
	dp[r][c]=0; //number of left moves == 0 for starting point
	q.push_front({r,c});

	while(!q.empty()){
		auto node = q.front();
		q.pop_front();

		ll ci = node.fi; //current cell row val
		ll cj = node.si; //current cell col val

		//checking for all 4 possible movement
		for(ll i=0; i<4; i++){
			ll ni = ci + rows[i]; //new row val after making movement
			ll nj = cj + cols[i];
			ll len = cost[i];
			//checking if (ni, nj) is valid or not
			if(isValid(ni, nj)){
				if(dp[ni][nj] == -1 || dp[ni][nj] > dp[ci][cj] + len){
					dp[ni][nj] = dp[ci][cj] + len;
					//if cost is 1 then we push_back, else push_front
					if(len){
						q.pb({ni, nj});
					}
					else{
						q.push_front({ni, nj});
					}
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
	cin>>n>>m>>r>>c>>x>>y;
	r--; c--;

	F(maze, n);

	solve();

	ll ans=0;


	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ll left = dp[i][j];
			ll right = left + j - c;
			//checking that right and left are within the range or not
			if(left <= x && right <= y && left>=0 && right>=0){
				ans++;
			} 
		}
	}

	cout<<ans;
}