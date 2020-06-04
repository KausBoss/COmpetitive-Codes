#include <bits/stdc++.h>

using namespace std;

#define ll long long

void generate(int i, int n, int open, int close, char *ans){
	//base case
	if(close == n){
		ans[i]='\0';
		cout<<ans<<endl;
		return;
	}
	//recusrive case
	if(open > close){
		ans[i]=')';
		generate(i+1, n, open, close+1, ans);
	}
	if(open < n){
		ans[i]='(';
		generate(i+1, n, open+1, close, ans);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n;
	char ch[100];
	cin>>n;
	generate(0, n, 0, 0, ch);
}