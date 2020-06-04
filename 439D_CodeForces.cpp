#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define F(a,n) for(int i=0; i<n; i++){ll temp;cin>>temp;a.push_back(temp);} 

int main(){
	int n, m;
	cin>>n>>m;
	vector<ll> a, b;
	a.reserve(n);
	b.reserve(m);

	F(a,n);
	F(b,m);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<ll>());
	ll ans=0;
	for(int i=0; i<n && i <m && a[i] < b[i]; i++){
		ans+= b[i] - a[i];
	}
	cout<<ans;
}