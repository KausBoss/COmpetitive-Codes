#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf (ll)(1e6)+1
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll k, sum[inf]={0}, ans=0, cnt=0;
	string s;
	cin>>k;
	cin>>s;
	sum[0]=1;
	for(ll i=0; i<s.length(); i++){
		cnt += s[i]-'0';
		if(cnt >= k){
			ans += sum[cnt-k];
		}
		sum[cnt]++;
	}
	cout<<ans;
}