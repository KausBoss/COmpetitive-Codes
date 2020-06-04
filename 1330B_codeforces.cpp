#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

#define ll long int

ll freq[200001]={0};

bool check(const vector<ll> v,ll s, ll e){
	int m = e-s;
	for(int i=1; i<=m; i++){freq[i]=0;}
	for(int i=s; i<e; i++){
		ll id = v[i];
		freq[id]++;
	}
	for(int i=1; i<=m; i++){
		if(freq[i]!=1){
			return false;
		}
	}
	
	return true;;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n, mx=0, count =0;
		cin>>n;
		vector<ll> v, ans;
		for(int i=0; i<n; i++){
			ll temp;
			cin>>temp;
			v.push_back(temp);
			mx = max(mx, temp);
		}
		for(ll i=1; i<n; i++){
			if(i == mx){
				bool left = check(v, 0, i);
				bool right = check(v, i, n);
				if(left && right){
					ans.push_back(i);
					count++;
				}
				continue;
			}
			else if((n-i) == mx){
				bool left = check(v, 0, i);
				bool right = check(v, i, n);
				if(left && right){
					ans.push_back(i);
					count++;
				}
				continue;
			}
		}
		cout<<count<<endl;
		if(count!=0){
			for(int i=0; i<ans.size(); i++){
				cout<<ans[i]<<" "<<n-ans[i]<<endl;
			}
		}
		ans.clear();
		v.clear();
	}
}