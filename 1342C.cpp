#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll GCD(ll a,ll b){
	//base case
	if(b==0){
		return a;
	}
	//recusive case
	return GCD(b, a%b);
}
ll LCM(ll a, ll b){
	return (a*b)/GCD(a, b);
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
		ll a, b, r, l;
		int q;
		cin>>a>>b;
		cin>>q;
		ll diff = b-a;
		ll qt= max(a, b) -1;
		ll mul=LCM(a, b);
		while(q--){
			ll l, r;
			cin>>l>>r;
			ll pehla = (l/mul)*mul;
			if(pehla < l){pehla += mul;}
			ll akhiri = (r/mul)*mul;
			ll kitne = ((akhiri - pehla)/mul) + 1;
			ll bekaar = qt*kitne;
			if(akhiri < pehla){bekaar=0;}
			for(ll i=l; i<min(r, max(a, b)); i++){
				if(i!=min(a, b)){bekaar++;}
			}
			cout<<(r-l)-bekaar<<" ";
		}
		cout<<endl;
	}
	
}