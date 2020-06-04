#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool isPossible(int a[][9], int i, int j, int n, int k){
	//checking for rows/cols
	for(int it=0; it<n; it++){
		if(a[i][it]==k || a[it][j]==k){
			return false;
		}
	}
	//checking for small grid
	n = sqrt(n);
	int row= (i/n)*n;
	int col= (j/n)*n;

	for(int ri=row; ri<row+n; ri++){
		for(int ci=col; ci<col+n; ci++){
			if(a[ri][ci] == k){
				return false;
			}
		}
	}
	return true;
}

void Print(int a[][9], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool solver(int a[][9], int i, int j, int n){
	//base case
	if(i==n){
		Print(a, n);
		return true;
	}
	//recusrive case
	if(j==n){
		return solver(a, i+1, 0, n);
	}
	if(a[i][j]!=0){
		return solver(a, i, j+1, n);
	}
	for(int k=1; k<=9; k++){
		if(isPossible(a, i, j, n, k)){
			a[i][j]=k;
			bool next = solver(a, i, j+1, n);
			if(next){
				return true;
			}
				a[i][j]=0;
			}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int a[9][9], n;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	solver(a, 0, 0, n);
}