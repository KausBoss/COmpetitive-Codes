#include <iostream>
using namespace std;
#define ll long long int
#define inf 1000001

int count =0;

int ans(int a[], int i, int j, int n, int dp[][inf]){
	//base case
	if(i>j || i == n || j == n){
		return 1;
	}
	if(i == j){
		return a[i];
	}
	//recursive case
	if(dp[i][j]!=0){return dp[i][j];}

	dp[i][j] = ans(a, i, j-1, n, dp)*(a[j]%4);
	dp[i][j] %= 4;
	if(dp[i][j]%2==1 ||dp[i][j]%4==0){
		count++;
	}
	ans(a, i+1, j, n, dp);

	return dp[i][j];
}

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, a[inf], dp[inf][inf]={0};
		count=0;
		ll temp;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>temp;
			temp %=4;
			a[i]=temp;
		}
		ans(a, 0, n-1, n, dp);
		cout<<count<<"\n";
	}
}