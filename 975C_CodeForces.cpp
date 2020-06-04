#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll unsigned long long

int main(){
	ll n, q;
	cin>>n>>q;
	vector<ll> stren, arrow;
	stren.push_back(0);
	for(int i=0; i<n; i++){
		ll temp; cin>>temp;
		stren.push_back(stren.back()+temp);
	}
	ll last=0, power, now, id=0;
	for(int i=0; i<q; i++){
		cin>>now;
		power = last + now;
		if(power >= stren.back()){
			cout<<n<<endl;
			last = 0;
		}
		else{
			id =n-(upper_bound(stren.begin(), stren.end(), power)- stren.begin()-1);
			cout<<id<<endl;
			last = power;
		}
	}
}