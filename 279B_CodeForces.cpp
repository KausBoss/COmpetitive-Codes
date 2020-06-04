#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main(){
	ll n, t, page;
	vector<ll> sum;
	cin>>n>>t;
	sum.push_back(0);
	for(int i=0; i<n; i++){
		cin>>page;
		sum.push_back(sum[sum.size()-1] + page);
	}
	
	ll ans=0, ct= 0;
	for(int i=1; i<=n;){
		if(sum[i] - sum[ct] <= t){
			ans = max(ans, i - ct);
			i++;
		}
		if(sum[i] - sum[ct] > t){
			ct++;
		}
	}
	cout<<ans;
}