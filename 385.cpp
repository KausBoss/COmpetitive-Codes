#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 20000001

bitset<inf> pr;
ll freq[inf]={0};
ll ct[inf]={0};
//vector<ll> freq(inf, 0);
//vector<ll> ct(inf, 0);


void sieve(){
	for(ll i=2; i<=inf; i++){
		if(!pr[i]){
			ct[i] += freq[i];
			for(ll j = i*2; j<=inf; j+=i){
				pr[j]=1;
				ct[i] +=freq[j];
			}
		}
	}

	for(ll i=2; i<=inf; i++){
		ct[i] += ct[i-1];
		// if(!pr[i]){
		// 	ct[i]+=freq[i];
		// }
	}
	for(int i=2; i<=inf; i++){
		//cout<<i<<" "<<ct[i]<<"--"<<freq[i]<<"--"<<pr[i]<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n, l, r, m, x;
	cin>>n;
	for(ll i=0; i<n; i++){
		cin>>x;
		freq[x]++;
	}
	sieve();
	 cin>>m;
	 for(ll i=0; i<m; i++){
	 	cin>>l>>r;
	 	if(l>inf){
			l = r = 0;
		}
		if(l<inf && r>inf){
			r= inf-1;
		}
		cout<<ct[r]-ct[l-1]<<"\n";
	}
}