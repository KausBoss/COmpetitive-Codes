#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

ll BS(ll *a, ll s, ll e, ll target){
	while(s<=e){
		ll mid = (s+e)/2;
		if(a[mid] <= target){
			s = mid+1;
		}
		else{
			e = mid -1;
		}
	}
	return s;
}

int main(){
	int n, m;
	cin>>n>>m;
	ll *a = new ll[n];
	ll *b = new ll[m];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<m; i++){
		cin>>b[i];
	}
	sort(a, a+n);
	for(int i=0; i<m; i++){
		cout<<BS(a, 0, n-1, b[i])<<" ";
	}
}