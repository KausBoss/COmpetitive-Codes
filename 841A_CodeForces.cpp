#include <iostream>

using namespace std;

int main(){
	string s;
	int n, k, ar[26] = {0};
	cin>>n>>k;
	cin>>s;
	for(int i=0; i<n; i++){
		int idx = s[i] - 'a';
		ar[idx]++;
		if(ar[idx] > k){
			cout<<"NO";
			n = -2;
			break;
		}
	}
	if(n!=-2){
		cout<<"YES";
	}
}