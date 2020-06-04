#include <bits/stdc++.h>

using namespace std;

int steps=0;

void TowerOfHanoi(int n, string s, string a, string d){
	//base case
	if(n == 0){
		return;
	}
	//recursive case
	TowerOfHanoi(n-1, s, d, a);
	cout<<"Move "<<n<<"th disc from "<<s<<" to "<<d<<endl;
	steps++;
	TowerOfHanoi(n-1, a, s, d);
}

int main(){
	int n;
	cin>>n;
	TowerOfHanoi(n, "T1", "T3", "T2");
	cout<<steps;
}