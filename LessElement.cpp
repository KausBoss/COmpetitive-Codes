#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
	ll n, m, temp;
	vector<ll> a,b;
	cin>>n>>m;
	for(ll i=0; i<n; i++){
		cin>>temp;
		a.push_back(temp);
	}
	for(ll i=0; i<m; i++){
		cin>>temp;
		b.push_back(temp);
	}
	sort(a.begin(), a.end());
	for(ll i=0; i<b.size(); i++){
		auto id1 = std::upper_bound(a.begin(), a.end(), b[i]) - a.begin();
		cout<<id1<<" ";
	}
}