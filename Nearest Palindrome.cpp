//Find Nearest Palindrome eg. i/p-123 o/p-121
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0; i<=n/2; i++){
		int a=s[i] - '0';
		int b=s[n-i-1] - '0';
		if(a!=b){
			s[n-i-1]=s[i];
		}
	}
	cout<<s<<endl;
}