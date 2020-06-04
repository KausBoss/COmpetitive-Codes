#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		ll x, y, a, b, ans;
		cin>>x>>y>>a>>b;
		if(x>=0 && y>=0 || x<=0 && y<=0){
			if(b < 2*a){
				ans = b*(min(abs(x), abs(y))) + a*(abs(x-y));
			}
			else{
				ans = a*abs(x+y);
			}
		}
		else{
			ans = a*(abs(x) + abs(y));
		}
		cout<<ans<<endl;
	}
}