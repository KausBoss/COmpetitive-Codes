#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long

int main(){
	ll t, n, a[100005];
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=0; i<n; i++){
			cin>>a[i];
		}
		sort(a, a+n);
		ll i,j;
		i = j = n/2;
		if(n%2==0){
			i--;
		}
		else{j++;}
		for(ll k=0; k<n; k++){
			if(k%2==0){
				cout<<a[i--]<<" ";
			}
			else{
				cout<<a[j++]<<" ";
			}
		}
		cout<<"\n";
	}
}