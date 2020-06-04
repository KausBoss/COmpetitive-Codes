#include <iostream>

using namespace std;

int steps(int n, int dp[]){
	//base case
	if(n == 1){
		return 0;
	}
	if(n == 2 || n == 3){
		return 1;
	}
	//recursive case
	if(dp[n]!=0){
		return dp[n];
	}
	int ans;
	if(n%3==0 && n%2==0){
		int a = steps(n/3, dp);
		int b = steps(n/2, dp);
		int c = steps(n-1, dp);
		ans =  min(a, min(b, c))+1;
	}
	if(n%3==0){
		int a = steps(n/3, dp);
		int c = steps(n-1, dp);
		ans = min(a, c)+1;
	}
	if(n%2==0){
		int b = steps(n/2, dp);
		int c = steps(n-1, dp);
		ans = min(b, c)+1;
	}
	else{
		ans =(steps(n-1, dp) +1) ;
	}
	dp[n] = ans;
	return ans;
}

int main(){
	int n, dp[10001]={0};
	cin>>n;
	cout<<steps(n, dp);
}