#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

#define mod 998244353
#define ll long long

bool comp(ll a, ll b){
	return a > b;
}

int main(){
	int n;
	cin>>n;	
	ll* a = new ll[n];
	ll* b = new ll[n];

	for(int i=0; i<n; i++){
		cin>>a[i];
		a[i] = ((a[i]%mod)*((i+1)%mod)*((n-i)%mod));
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	sort(a, a+n);
	sort(b, b+n, comp);

	ll sum=0;
	for(int i=0; i<n; i++){
		sum += ((a[i]%mod)*(b[i]%mod))%mod;
		sum %= mod;
	}
	cout<<sum;
}