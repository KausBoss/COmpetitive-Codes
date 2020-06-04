#include <bits/stdc++.h>

using namespace std;
#define ll long long

int Count=0;

void path(int n1, int i, int j, int k, char *ch){
	//base case
	if(i==(n1-1) && j==(n1-1)){
		ch[k]='\0';
		cout<<ch<<" ";
		Count++;
		return;
	}
	if(i>=n1){return;}
	if(j>=n1){return;}
	//recursive case
	ch[k]='V';
	path(n1, i+1, j, k+1, ch);
	ch[k]='H';
	path(n1, i, j+1, k+1, ch);
	if(i==j || i+j==n1-1){
		ch[k]='D';
	path(n1, i+1, j+1, k+1, ch);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n1;
	char ch[100];
	cin>>n1;
	path(n1, 0, 0, 0, ch);
	cout<<"\n"<<Count;
}