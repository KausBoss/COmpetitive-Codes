#include <iostream>
#include <climits>

using namespace std;

#define ll long long

int main(){
	ll n, k;
	int h[150007];
	ll back[150007];
	cin>>n>>k;

	for(int i=0; i<n; i++){
		cin>>h[i];
		if(i == 0){
			back[i] = h[i];
		}
		else{
			back[i] = h[i] + back[i-1];
		}
	}
	ll ans_sum =back[k-1], op=0;
	for(int i=k; i<n; i++){
		ll sum_here = back[i] - back[i-k];
		if(sum_here < ans_sum){
			op = i-k +1;
		}
		ans_sum = min(ans_sum, sum_here);
	}
	cout<<op+1;
}
