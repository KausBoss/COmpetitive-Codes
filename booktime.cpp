#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main(){
	ll n, temp;
	ll t;
	vector <ll> book;
	cin>>n>>t;
	for(int i=0; i<n; i++){
		cin>>temp;
		book.push_back(temp);
	}
	ll ans=0, i=0, st=0;
	ll sum =0;
	while(i<n){
		if(book[i] > t){
			i++;
			continue;
		}
		if(sum+book[i] > t){
			sum = sum - book[st];
			st++;
		}
		else{
			sum += book[i];
			ans = max(ans, i-st);
			i++;
		}
	}
	cout<<ans+1;
}