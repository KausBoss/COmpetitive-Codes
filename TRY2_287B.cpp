#include <iostream>

using namespace std;

typedef unsigned long long uint_64_t;
#define ll uint_64_t

bool possible(ll n, ll tri, ll k){
	//base case
	if(n == 0){
		return true;
	}
	if(tri == 0){
		return false;
	}
	if(tri == k && (k*(k+1)/2)-(k-1) < n){
		return false;
	}
	//recursive case
	if(k >= n){
		return true; 
	}
	n = n - k +1;

	return possible(n, tri - 1, k-1) ;
}

ll kaustubh_dhoondega_number(ll n, ll s, ll e, ll k){
	static ll ans = 0;
	//base case
	if(n <= k){
		return 1;
	}
	if(s > e){
		return ans;
	}
	//recursive case
	ll mid = (s+e)/2;
	//cout<<s<<"  "<<mid<<"  "<<e<<endl;

	if(possible(n, mid, k)){
		ans = mid;
		return kaustubh_dhoondega_number(n, s, mid-1, k);
	}
	else{
		return kaustubh_dhoondega_number(n, mid+1, e, k);
	}
}

int main(){
	ll n, k;
	cin>>n>>k;
	ll ans = kaustubh_dhoondega_number(n, 1, k, k);
	if(ans!=0){
		cout<<ans;
	}
	else{
		cout<<-1;
	}
}