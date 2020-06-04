#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define ll signed long long

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n, temp;
		cin>>n;
		ll maxa=INT_MIN, maxb=INT_MIN;
		for(int i=0; i<n; i++){
			cin>>temp;
			maxa = max(maxa, temp);
		} 
		for(int i=0; i<n; i++){
			cin>>temp;
			maxb = max(maxb, temp);
		}
		if(maxa == maxb){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
}