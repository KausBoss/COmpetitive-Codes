#include <iostream>
#include <math.h>
using namespace std;

#define ll unsigned long long

ll primeFactors(ll n){
	ll count=0;
    while (n % 2 == 0){  
        count++;
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2){  
        while (n % i == 0)  
        {  
            count++;  
            n = n/i;  
        }  
    }
    if(n > 2){count++;}
    return count;
}  

int main(){

	ll t;
	cin>>t;
	while(t--){
		ll x, k;
		cin>>x>>k;
		ll count = primeFactors(x);
		//cout<<count<<endl;
		if(count >= k){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
}