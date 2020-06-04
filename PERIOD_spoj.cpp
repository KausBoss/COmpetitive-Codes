#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 1000000
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	for(int ii=1; ii<=t; ii++){
		cout<<"Test case #"<<ii<<endl;
		int n, table[inf]={0};
		string s;
		cin>>n;
		cin>>s;
		int i=0, j=1;
		while(j<n){
			if(s[i] == s[j]){
				table[j] = i+1;
				i++; j++;
			}
			else{
				if(i==0){
					j++;
				}
				else{
					i=0;
				}
			}
		}
		for(int i=0; i<n; i++){
			if(table[i] > 0){
				if((i+1)%((i+1)-table[i]) == 0){
					cout<<i+1<<" "<<(i+1)/((i+1)-table[i])<<endl;
				}
			}
		}
		cout<<endl;
	}
}