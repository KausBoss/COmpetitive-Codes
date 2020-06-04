#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long int

#define mod 1000000007

int main(){
	ll t, n, comp = 0;
	vector<ll> v;
	cin>>t;
	while(t--){
		cin>>n;
		ll temp, sum =0;
		for(int i=0; i<n; i++){
			cin>>temp;
			if(temp!=0){
				v.push_back(temp);
			}
		}
		sort(v.begin(), v.end(), greater<ll>());
		ll id = 0;
		for(int i=0; i<v.size(); i++){
			if(v[i]-id > 0){
				temp = v[i]-id;
				sum += temp;
				sum %= mod;
				id++;
			}
		}
		cout<<sum<<endl;
		v.clear();
	}
}