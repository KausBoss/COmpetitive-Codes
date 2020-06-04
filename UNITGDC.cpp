
#include <bits/stdc++.h>

using namespace std;

#define ll long int
#define inf 1000009

vector<ll> v;

vector<ll> Sieve(ll n){
	bool pr[inf];
    memset(pr, true, inf); 
 	for (ll p=2; (p*p)<=n; p++){
 		//cout<<p<<"-"<<pr[p]<<"   ";  
        if (pr[p] == true){
            for (ll i=p*p; i<=n; i += p){
                pr[i] = false; 
            }
        } 
    }
    //for(int i=0; i<inf; i++){cout<<i<<"-"<<pr[i]<<"  ";}
    for(int i=2; i<inf; i++){
    	if(pr[i]==true){
    		v.push_back(i);
    	}
    }
    return v;
}

int main(){
	vector<ll> prime = Sieve(inf);
	//for(int i=0; i<prime.size(); i++){cout<<prime[i]<<" ";}
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n == 1){
			cout<<1<<"\n"<<1<<" "<<1<<endl;
			continue;
		}
		cout<<n/2<<endl;
		vector <ll> print[n/2];
		print[0].push_back(1);
		for(int i=0; prime[i]<=n; i++){
			print[0].push_back(prime[i]);
		}
		cout<<print[0].size()<<" ";
			for(int j=0; j<print[0].size(); j++){
				cout<<print[0][j]<<" ";
			}
			cout<<endl;
		for(int i=1; i<n/2; i++){
			print[i].push_back(2*(i+1));

			for(int j=1; (prime[j]*prime[j+i-1])<=n; j++){
				print[i].push_back( prime[j]*prime[j+i-1]);
			}
			ll sz = print[i].size();

			if(sz == 1){
				cout<<2<<" "<<1<<" ";
			}
			else{
				cout<<sz<<" ";
			}

			for(int j=0; j<print[i].size(); j++){
				cout<<print[i][j]<<" ";
			}
			cout<<endl;
		}

	}
}