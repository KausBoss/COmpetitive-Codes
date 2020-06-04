#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
	ll n, m;
	cin>>n>>m;
	ll sum[100000]={0};
	for(int i=0; i<n; i++){
		ll t, d;
		cin>>t>>d;
		if(i == 0){
			sum[0] = t*d;
		}
		else{
			sum[i] = sum[i-1] + t*d;
		}
	}
	ll mo;
	for(int i=0; i<m; i++){
		cin>>mo;
		auto id = lower_bound(sum, sum+n, mo) - sum;
		cout<<id+1<<endl;
	}
}