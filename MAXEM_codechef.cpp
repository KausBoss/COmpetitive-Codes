#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 998244353

ll power(ll a, ll b){
	a %= mod;
	ll ret=1;
	while(b>0){
		if(b%2){
			ret *=a;
			ret %=mod;
		}
		a *=a;
		a %=mod;
		b /=2;
	}
	return ret;
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
		int n;
		ll maxA=0;
		map<ll,ll> m;
		cin>>n;
		vector <ll> a(n);
		for(ll i=0; i<n; i++){
			cin>>a[i];
			maxA=max(maxA, a[i]);
			if(m.count(a[i])){m[a[i]]++;}
			else{m[a[i]]=1;}
		}	
		sort(a.begin(), a.end());
		ll ans=0, t1, t2, gm, l;
		t2=1;
		for(ll i=1; i<=maxA+1; i++){
			l = upper_bound(a.begin(), a.end(), (ll)i) - a.begin();
			gm = n-l;
			t1 = (i%mod)*power((ll)2, (ll)gm);
			t1 %=mod;
			//t2=1;
			//cout<<i<<"__"<<gm<<"__"<<l<<" finally t1 is "<<t1/i<<endl;
			if(m.count(i-1)){
				t2 *= power((ll)2, m[i-1]) - 1;
				t2 %= mod;
			}
			// for(ll j=1; j<i; j++){
			// 	if(m.count(j)){
			// 		t2 *= power((ll)2, m[j]) - 1;
			// 		t2 %= mod;
			// 		//cout<<j<<"**"<<m[j]<<"**"<<t2<<endl;
			// 	}
				
			// }
			ans += t1*t2;
			ans %=mod;
			if(m.count(i)==0){break;}
		}
		cout<<ans<<endl;
	}
}