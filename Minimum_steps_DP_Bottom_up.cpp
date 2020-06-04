#include <iostream>
#include <climits>

using namespace std;

int main(){
	int n, dp[10001]={0};
	cin>>n;
	dp[1] = 0;
	for(int i=2; i<=n; i++){
		int op1, op2, op3;
		op1 = op2 = INT_MAX;
		if(n%3==0){
			op1 = dp[i/3];
		}
		if(n%2==0){
			op2 = dp[i/2];
		}
		op3 = dp[i-1];
		dp[i] = min(op1, min(op2, op3)) + 1;
	}
	cout<<dp[n]<<endl;
}