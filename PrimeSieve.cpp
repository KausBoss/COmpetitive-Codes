#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e4+5;
const int mod = 1e9+7;
vector<ll> prime;

//sieve is used to find all prime numbers from 1 till n
//time complexity is O(N*loglogN)



void PrimeSieve(ll n){
	vector<bool> Pr(n+1, 1);
	for(ll i=3; i*i<=n; i+=2){//not checking for 2 as we know all even no. are not prime
		if(Pr[i]){
			for(ll j=3; i*j<=n; j+=2){
				Pr[i*j]=0;
			}
		}
	}
	prime.pb(2); 
	//cout<<2<<" ";//doing manually for 2
	for(ll i=3; i<=n; i+=2){
		if(Pr[i]){
			//cout<<i<<endl;
			prime.pb(i);
		}
	}
	return;
}
//segment Sieve
//when |b-a| <= 10^6, but b and a are very large
//we use index mapping to map a with the 0th element of the array
//we need prime sieve of only root(b) numbers to check for numbers till b
//for each prime number between 2 till root(b) we cancel out all their mutiple between [a, b]

void SegmentSieve(ll a, ll b){
	vector<bool> op((b-a)+1, 1); // index mapped array, intially we assume all numbers are prime

	PrimeSieve(sqrt(b));

	for(ll i=0; (prime[i]*prime[i])<=b &&(i<prime.size()); i++){
		ll n= prime[i];
		ll start =(a/n)*n;
		if(start < a){start += n;}

		for(ll j=start; j<=b; j+= n){
			op[j-a] = 0;
		}
		if(n == start){op[start-a]=1;}
	}

	for(ll i=0; i<op.size(); i++){
		if(op[i]){
			cout<<(i+a)<<" ";
		}
	}
}
int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	//PrimeSieve(1000);
	ll a= 131;
	ll b=8273;
    SegmentSieve(a, b);
}