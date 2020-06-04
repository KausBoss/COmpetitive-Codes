#include <iostream>

using namespace std;

int Count_ways(int n, int i, int k, int dp[]){
	//base case
	if(i > n){
		return 0;
	}
	if(i == n){
		return 1;
	}
	//recursive case
	if(dp[i]!=0){return dp[i];}
	int total = 0;
	for(int j=1; j<=k; j++){
		total += Count_ways(n, i+j, k, dp);
	}
	dp[i]= total;
	return total;
}

int main(){
	int n, k;
	int dp[100]={0};
	cin>>n>>k;
	cout<<"Ways: "<<Count_ways(n, 0, k, dp);
}