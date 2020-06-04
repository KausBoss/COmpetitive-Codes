#include <bits/stdc++.h>
using namespace std;

set<string> op;

void recc(int n){
	//base case
	if(n<0){
		return;
	}
	//recusrive case
	op.insert(to_string(n));
	recc(n-1);
}


int main(){
	int n;
	cin>>n;
	recc(n);
	for(auto x:op){
		cout<<x<<" ";
	}
}