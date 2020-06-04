#include <bits/stdc++.h>

using namespace std;

#define ll long long

void func(){
	map<ll, vector<ll> > m;
	ll n, temp, ans=0;
	cin>>n;
	for(ll i=0; i<n; i++){
		cin>>temp;
		m[temp].push_back(i);
	}
	for(auto x:m){
		sort(x.second.begin(), x.second.end());
	}

	ll pos= *(m.begin()->second.begin());

	for(auto it=m.begin(); it!=m.end(); it++){
		auto c=it;
		c++;
		if(c==m.end()){break;}
		auto next = upper_bound(c->second.begin(), c->second.end(), pos);
		cout<<"number: "<<it->first<<", position: "<<pos<<" , next position: "<<*next<<endl;
		if(next != c->second.end()){
			pos=*next;
		}
		else{
			ans++;
			pos=*(c->second.begin());
		}
	}
	cout<<ans+1<<endl;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		func();
	}
}