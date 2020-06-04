#include <bits/stdc++.h>

using namespace std;

#define ll long long

int GCD(int a, int b){
	//base case
	if(b==0){
		return a;
	}
	//recusive case
	return GCD(b, a%b);
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int a, b;
	cin>>a>>b;
	if(a<b){swap(a, b);}
	cout<<GCD(a, b);
}