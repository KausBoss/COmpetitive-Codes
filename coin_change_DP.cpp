#include <iostream>
#include <ctime>
#include <climits>
using namespace std;

int change[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

int find_change(int n, int dp[]){
	//base case
	if(n == 0){
		return 0;
	}
	//recursive case 
	if(dp[n]!=0){
		return dp[n];
	}
	int ret = INT_MAX;
	for(int i=0;change[i] <= n; i++){
		int at_here = find_change(n-change[i], dp);
		ret = min(ret, at_here);
	}
	dp[n]= ret + 1;
	return ret + 1; 
}

//bottom up
int changeBP(int n, int ar[]){
	ar[0] = 0;
	ar[1] = 1;
	for(int i=2; i<=n; i++){
		int here = INT_MAX;
		for(int j=0;j < 10; j++){
			if(i - change[j] >= 0){
				int temp = ar[i - change[j]];
				here = min(here, temp);
			}
		}
		ar[i] = here +1;
	}
	return ar[n];
}

int main(){
	int n;
	int dp[10000] = {0};
	cin>>n;
	clock_t start = clock();
	cout<<find_change(n, dp);
	clock_t end = clock();
	int ar[n]={0};
	cout<<endl<<changeBP(n, ar);
}