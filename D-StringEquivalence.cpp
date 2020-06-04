#include <bits/stdc++.h>

using namespace std;

void func(char *st, int i, int n, char last){
	//base case
	if(i == n){
		st[i]= '\0';
		cout<<st<<"\n";
		return;
	}
	//recursive case
	for(char j='a'; j<=last+1; j++){
		st[i] = j;
		func(st, i+1, n, max(j, last));
	}
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n;
	char st[11];
	cin>>n;
	func(st, 0, n, 'a'-1);
}