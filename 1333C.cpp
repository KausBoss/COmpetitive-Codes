#include <iostream>
#include <math.h>
#include <map>
using namespace std;

#define inf 200005
#define ll signed long long

ll count=0;



int main(){
	ll n, a, t=0;
	map<ll, int> m;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		t += a;
		if(m.count(t)){
			m[t]++;
		}
		else{
			m[t]=1;
		}
	}
	ll count = 0;
	ll x = m.find(0)->second;
	//cout<<"+++"<<x<<endl;
	count += x;
	for(auto it=m.begin(); it!=m.end(); it++){
		if(it->second > 1 && it->first!=0){
			//cout<<it->first<<"--"<<it->second<<endl;
			ll r = it->second;
			count += r;
		}
	}
	ll total = (n)*(n+1)/2;
	cout<<total-count;
}