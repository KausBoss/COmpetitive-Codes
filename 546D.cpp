#include <bits/stdc++.h>

using namespace std;
#define ll long long int

#define nax  (ll)5e6+5

bitset<nax> pr;
vector<ll> divisor(nax+1, 1);
vector<ll> sumFact(nax+1, 0);
vector<ll> fact(nax+1, 0);

void sieve(){
	pr[0]=pr[1]=1;
	for(ll i=2; (i*i)<=nax; i++){
		if(!pr[i]){
			for(ll j=2; (i*j)<=nax; j++){
				pr[i*j] = 1;
				divisor[i*j] = i;
			}
		}
	}
}

void Preprocessing(){
	for(ll i=2; i<=nax; i++){
		if(!pr[i]){
			fact[i]=1;// prime no. will have only one factor
		}
		else{
			fact[i] = fact[i/(divisor[i])] +1; // divisor[i] stores HCF of the i 
		}
		sumFact[i] = sumFact[i-1] + fact[i]; // making prefix sum array
	}
}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	sieve();
	Preprocessing();
	ll t;
	cin>>t;
	while(t--){
		ll a, b;
		cin>>a>>b;
		cout<<(sumFact[a]-sumFact[b])<<"\n";//difference of prefix sum array
	}
}