#include <iostream>

using namespace std;

#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		ll a, b;
		cin>>a>>b;
		ll op = b-(a%b);
		if(op == b){
			cout<<0<<endl;
		}
		else{
			cout<<op<<endl;
		}
	}
}