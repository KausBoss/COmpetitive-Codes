#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
	int n;
	cin>>n;
	vector<ll> h, rmin;
	ll sum;
	for(int i=0; i<n; i++){
		ll temp;
		cin>>temp;
		h.push_back(temp);
	}
	sum = h[n-1];
	rmin.push_back(sum); 
	for(int i=n-2; i>=0; i--){
		sum = min(sum, h[i]);
		rmin.push_back(sum);
	}
	std::reverse(rmin.begin(), rmin.end());
	int ans =1;
	ll lmax = h[0];
	for(int i=0; i<n-1; i++){
		if(lmax <= rmin[i+1]){
			ans++;
			lmax = h[i+1];
		}
		else{
			lmax = max(lmax, h[i+1]);
		}
	}
	cout<<ans;
}