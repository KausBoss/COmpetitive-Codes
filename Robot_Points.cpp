#include <bits/stdc++.h>

using namespace std;

#define ll long long
int final=0;

int MaxPoints(int a[][5], int i, int j, int n, int high, int low){
	//base case
	if(i < 0){
		return 0;
	}
	//recursive case
	int left, right, seedha;
	left = right = seedha =-2;
	int ret = a[i][j];
	if((ret==-1) && (i>=low) && (i<=high)){ret=0;}

	seedha = MaxPoints(a, i-1, j, n, high, low);

	if(j!=0){
		left = MaxPoints(a, i-1, j-1, n, high, low);
	}
	if(j!=n-1){
		right = MaxPoints(a, i-1, j+1, n, high, low);
	}
	return (ret + max(left, max(seedha, right)));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		final=0;
		int n, a[13][5];
		cin>>n;
		for(int i=0; i<n; i++){
			for(int j=0; j<5; j++){
				cin>>a[i][j];
			}
		}
		for(int i=0; i<5; i++){a[n][i]=0;}

		for(int i=n-1; i>=4; i--){
			int cur= MaxPoints(a, n, 2, n, i, i-4);
			final = max(cur, final);
		}
		cout<<final<<endl;
	}
}