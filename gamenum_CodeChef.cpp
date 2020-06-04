#include <iostream>
#include <climits>
#include <math.h>
using namespace std;

#define ll uint64_t

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll a, b, ans, temp;
		cin>>a>>b;
		ans= (a^b);
		ll cb =0, shift=0;
		temp = max(a,b);
		while(temp>0){
			temp = temp>>1;
			cb++;
		}
		for(int i=1; i<cb; i++){
			//cout<<cb<<" "<<i<<" "<<ans<<" "<<shift<<endl;
			temp = b;
			ll m =pow(2, i);
			m--;
			m = m&temp;
			temp = temp>>i;
			m = m<<(cb-i);
			m = m|temp;
			if((m^a) > ans){shift = i;}
			ans = max(ans, (m^a));
		}
		cout<<shift<<" "<<ans<<endl;
	}
}