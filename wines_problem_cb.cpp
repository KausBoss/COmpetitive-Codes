#include <iostream>

using namespace std;

int wine(int a[], int i, int j, int n, int dp[][100]){
	//base case
	if(i>j){
		return 0;
	}
	//recursive case 
	if(dp[i][j]!=0){return dp[i][j];}

	int y = n-(j-i);
	int left = y*a[i] + wine(a, i+1, j, n, dp);
	int right = y*a[j] + wine(a, i, j-1, n, dp);
	dp[i][j] = max(left, right);
	return dp[i][j];
}

int main(){
	int dp[100][100]={0};
	int a[100];
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<wine(a, 0, n-1, n, dp);
}