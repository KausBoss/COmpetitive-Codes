#include <iostream>

using namespace std;

#define ll long long
#define inf 1e9

ll Robinhood(ll n, ll k, ll* a){
	ll s = 1;
	ll e = inf +100;
	ll total=0;
	ll mid=0, min=0, max=0;

	for(int i=0; i<n; i++){
		total += a[i];
	}

	while(s<=e){
		ll mid = (s+e)/2;
		ll sum =0;
		for(int i=0; i<n; i++){
			if(mid-a[i]>0){sum+=mid-a[i];}
		}
		if(sum <= k){
			min = mid;
			s = mid +1;
		}
		else{
			e = mid -1;
		}
	}
	s = 1;
	e = inf +100;
	while(s<=e){
		ll mid = (s+e)/2;
		ll sum =0;
		for(int i=0; i<n; i++){
			if(a[i]-mid>0){sum+=a[i]-mid;}
		}
		if(sum <= k){
			max = mid;
			e = mid -1;
		}
		else{
			s = mid +1;
		}
	}

	return max-min>0?max-min:(total%n==0?0:1);

}

int main(){
	ll n, k;
	cin>>n>>k;
	ll* a = new ll[n+1];
	for(int i=0; i<n; i++){
		cin>>a[i]; 
	}
	cout<<Robinhood(n, k, a);
}