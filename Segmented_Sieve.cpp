#include <iostream>
#include <math.h>
#include <bitset>
#include <vector>
#include <cstring>
using namespace std;

#define inf 1000002
#define ll long long

void findPrimes(vector<ll> &prime){
	bitset<inf> pr;
	for(ll i=3; i*i<=inf; i++){
		if(!pr[i]){
			for(ll j=i*i; j<=inf; j+=2*i){
				pr[j]=1;
			}
		}
	}
	prime.push_back(2);
	for(ll i=3;i<inf; i+=2){
		if(!pr[i]){prime.push_back(i);}
	}
}

void segment_sieve(ll a, ll b, vector<ll> &prime){
	ll t=b-a+1;
	bool ans[t];
	memset(ans, false, sizeof(ans));
	//for(int i=0; i<100;i++){cout<<prime[i]<<" ";}
	for(int i=0; prime[i]*prime[i]<=b; i++){
		ll n = prime[i];
		ll start = (a/n)*n;
		if(start < a){start += n;}

		ll end = (b/n)*n;

		for(ll j= start; j<=end; j+=n){
			if(j!=n){
				ans[j-a]=1;
			}
		}
	}
	if(a==1){ans[]}
	for(int i=a; i<=b; i++){
		if(ans[i-a]==0){
			cout<<i<<"\n";
		}
	}
}

int main(){
	vector<ll> prime;
	findPrimes(prime);
	int t;
	cin>>t;
	while(t--){
		ll a, b;
		cin>>a>>b;
		segment_sieve(a, b, prime);
	}
}