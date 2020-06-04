#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define inf 200005

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	map<ll, multiset<ll>> m;
	ll n, a[inf], temp, ans=0;
	cin>>n;
	for(ll i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>temp;
		m[a[i]].insert(-temp);
	}

	for(auto it=m.begin(); it!=m.end(); it++){
		ll key= it->first +1;
		while(it->second.size() > 1){
			ll cost = *(++(it->second.begin()));
			//choosing optimum position
			while(m.count(key)){
				if(*(m[key].begin()) > cost){break;}
				key++;
			}
			//cout<<cost<<" goes to "<<key<<" from "<<it->first<<endl;
			ans += (key-(it->first))*cost;
			it->second.erase(cost);
			m[key].insert(cost);
			key++;
		}
	}
	cout<<-ans;
}