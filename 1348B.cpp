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
	int t;
	cin>>t;
	while(t--){
		int n, k, temp;
		set<int> s;
		cin>>n>>k;
		for(int i=0; i<n; i++){
			cin>>temp;
			s.insert(temp);
		}
		if(s.size()>k){
			cout<<-1<<"\n";
			continue;
		}
		cout<<n*k<<"\n";
		for(int i=0; i<n; i++){
			for(auto x:s){
				cout<<x<<" ";
			}
			int j=k-s.size();
			while(j--){
				cout<<2<<" ";
			}
		}
		cout<<"\n";
	}
}