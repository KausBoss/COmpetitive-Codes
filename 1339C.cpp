#include <iostream>
#include<math.h>

using namespace std;

#define ll long long 

int main(){
	ll t, n, a[100005];
	cin>>t;
	while(t--){
		cin>>n;
		ll many=0, diff=0;
		for(int i=0; i<n; i++){
			cin>>a[i];
			if(i>0){
				if(a[i] < a[i-1]){
					many++;
					diff= max(diff, a[i-1]-a[i]);
				}
			}
		}
		ll t= log2(diff);
		if(pow(2,t)<diff){
			if(pow())
		}
		t++;
		cout<<max(t, many)<<"\n";
	}
}