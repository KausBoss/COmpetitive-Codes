#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

int main(){
	int n;
	cin>>n;
	vector<ll> arr;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	ll ans=0;
	for(int i=0;i<n; i++){
		ans += abs(arr[i] - (i+1));
	}
	cout<<ans;
}