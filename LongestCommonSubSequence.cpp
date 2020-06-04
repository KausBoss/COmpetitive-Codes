#include <bits/stdc++.h>

using namespace std;

#define ll long long

string memo[200][200];

bool comp(string a, string b){
	return a.length() < b.length();
}

string LCS(int i, int j, string s1, string s2){
	//base case
	if(i==s1.length() || j==s2.length()){
		return "";
	}
	//recusrive case
	if(!memo[i][j].empty()){
		return memo[i][j];
	}
	if(s1[i] == s2[j]){
		memo[i][j]= s1[i] + LCS(i+1, j+1, s1, s2);
		return memo[i][j]; 
	}
	else{
		memo[i][j]= max(LCS(i+1, j, s1, s2), LCS(i, j+1, s1, s2), comp);
		return memo[i][j];
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s1, s2;
	// getline(cin, s1);
	// getline(cin, s2);
	cin>>s1>>s2;
	cout<<LCS(0, 0, s1, s2);
}