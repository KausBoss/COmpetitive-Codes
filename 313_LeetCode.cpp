#include <bits/stdc++.h>
using namespace std;
#define ll long long

int nthSuperUglyNumber(int n, vector<int>& primes) {
    int nn=primes.size();
    vector<int> id(nn, 0);
    int mini;
    vector<int> v(1,1);
    while(v.size()<n){
    	mini=INT_MAX;
    	for(int i=0; i<primes.size(); i++){
    		mini = min(mini, v[id[i]]*primes[i]);
    	}
    	for(int i=0; i<primes.size(); i++){
    		if(mini ==  v[id[i]]*primes[i]){
    			id[i]++;
    		}
    	}
    	v.push_back(mini);
    }
    return v.back();
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> primes{2,7,13,19};
	int n=12;
	cout<<nthSuperUglyNumber(n, primes);	
}