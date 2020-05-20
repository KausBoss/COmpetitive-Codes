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

vector<int> threeEqualParts(vector<int> A) {
    int n=A.size();
    int countone=0, start=-1, mid=-1, temp=0, end;
    for(auto x:A){ if(x==1){ countone++;}}
    if(countone == 0){ return {0, n-1};}
	if(countone%3!=0){ return {-1,-1};}
	for(int i=0; i<n; i++){
		if(A[i]==1){
			temp++;
			if(start==-1){
				start=i;
			}
			if(temp >(countone/3) && mid==-1){
				mid = i;
			}
			if(temp > 2*(countone/3)){
				end=i;
				break;
			}
		}
	}
	while(end<n && A[end]==A[start] && A[mid]==A[start]){
		end++; start++; mid++;
	}
	if(end == n){
		return {start-1, mid};
	}
	return {-1,-1};
}


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> v{0,1,0,0,0,0,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,0,1,1,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,1,0,0,0};
	threeEqualParts(v);
}
