#include <bits/stdc++.h>

using namespace std;

#define ll long long
int ct=0;

bool possible(int a[][10], int i, int j, int n){
	if(i-2>=0){
		if(j+1<n){
			if(a[i-2][j+1]==1){
				return false;
			}
		}
		if(j-1>=0){
			if(a[i-2][j-1]==1){
				return false;
			}
		}
	}
	if(i-1>=0){
		if(j+2<n){
			if(a[i-1][j+2]==1){
				return false;
			}
		}
		if(j-2>=0){
			if(a[i-1][j-2]==1){
				return false;
			}
		}
	}
	return true;
}

void print(int mat[][10], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			//cout<<mat[i][j]<<" ";
			if(mat[i][j]==1){
				cout<<"{"<<i<<"-"<<j<<"} ";
			}
		}
		//cout<<endl;
	}
	cout<<" ";
	//cout<<endl;
}

bool NKnight(int mat[][10], int i, int j, int n, int placed){
	//base case
	if(i==n){return false;}
	if(placed == n){
		ct++;
		print(mat, n);
		return false;
	}

	//recusrive case
	if(j==n){
		return NKnight(mat, i+1, 0, n, placed);
	}

	for(int k=j; k<n; k++){
		if(possible(mat, i, k, n)){
			mat[i][k]=1;
			bool nextPos = NKnight(mat, i, k+1, n, placed+1);
			if(nextPos){
				return true;
			}
			mat[i][k]=0;
		}
	}
	return NKnight(mat, i+1, 0, n, placed);
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n, mat[10][10]={0};
	cin>>n;
	NKnight(mat, 0, 0, n, 0);
	cout<<endl<<ct;
}