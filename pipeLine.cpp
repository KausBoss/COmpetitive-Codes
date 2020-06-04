#include <iostream>
#include <climits>

using namespace std;

typedef unsigned long long uint_64_t;
#define ll uint_64_t

#define F(a) (a*(a+1)/2)

bool possible(ll n, ll tri, ll k){
	//base case
	ll diff = k-tri;
	ll kitna_bana = F(k) - F(diff) - (tri-1);
	if(kitna_bana >= n){
		return true;
	}
	return false;
}

ll kaustubh_dhoondega_number(ll n, ll s, ll e, ll k){
	static ll ans = 0;
	//base case
	if(n == 1){
		return 0;
	}
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
		if(n == 1){
			cout<<0;
		}
		else{
			cout<<-1;
		}
	}
}