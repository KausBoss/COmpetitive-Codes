#include<iostream>

using namespace std;

#define ll long long

int main(){
	ll t, n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1|| n==2){
			cout<<0<<"\n";
			continue;
		}
		if(n%2==1){
			cout<<n/2<<"\n";
		}
		else{
			cout<<(n/2)-1<<"\n";
		}
	}
}