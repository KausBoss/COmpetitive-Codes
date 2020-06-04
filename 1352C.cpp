#include <bits/stdc++.h>

using namespace std;

#define ll long long

void func(){
	ll n, k;
	cin>>n>>k;
	if(n>k){cout<<k<<endl; return;}
	ll s= 1, e=k;
	ll mul;
	while(s<=e){
		ll mid = (s+e)/2;
		ll val = mid*(n-1);
		if(val==k){
			mul=mid;
			break;
		}
		else if(val < k){
			s= mid+1;
		}
		else{
			mul=mid;
			e=mid-1;
		}
	}
	//cout<<mul<<"++"<<endl;
	ll vj = (mul*n)-1;
	ll diff = mul*(n-1) -k;
	ll ans = vj - diff;
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		func();
	}
}