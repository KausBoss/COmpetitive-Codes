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

ll dist[25][25] = {0};
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
char a[25][25];
ll row, col;
ll src_x, src_y, des_x, des_y;

bool valid(ll i, ll j){
	return (i>=0 && i<row && j>=0 && j<col && a[i][j]!='X');
}

void Dij(){
	dist[src_x][src_y] = 0;
	queue<pair<ll,ll>> q;
	q.push({src_x, src_y});

	while(!q.empty()){
		auto x = q.front();
		q.pop();
		ll ci= x.fi;
		ll cj= x.si;

		for(ll i=0; i<4; i++){
			ll ni = ci + dx[i];
			ll nj = cj + dy[i];

			if(valid(ni, nj) && dist[ni][nj] > (dist[ci][cj] + (a[ni][nj] - '0'))){
				dist[ni][nj] = dist[ci][cj] + (a[ni][nj] - '0');
				q.push({ni, nj});
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
	cin>>col>>row;

	while(col && row){
		for(ll i=0; i<row; i++){
			for(ll j =0; j<col ; j++){
				char ch;
				cin>>ch;
				a[i][j]=ch;
				if(ch == 'S'){
					src_x=i;
					src_y=j;
					a[i][j]='0';
				}
				if(ch == 'D'){
					des_x=i;
					des_y=j;
					a[i][j]='0';
				}
				dist[i][j] = 1e9;
			}
		}
		Dij();
		cout<<dist[des_x][des_y]<<endl;
		cin>>col>>row;
	}
}
