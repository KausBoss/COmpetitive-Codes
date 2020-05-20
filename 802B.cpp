#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n, s;
	cin>>n>>s;
	ll *a = new ll[n];
	map<ll, ll> m, m2;
	map<ll, set<ll>> id;
	for(ll i=0; i<n; i++){
		cin>>a[i];
		if(id.count(a[i])==0){
			id[a[i]].insert(n*a[i]);
		}
		id[a[i]].insert(i);
	}
	ll ans=0;

	for(ll i=0; i<n; i++){
		//cout<<"at "<<a[i]<<" "<<i<<" size m2 "<<m2.size()<<endl;
		if(m.count(a[i])==0){
			ans++;
			if(m.size() == s){
				vector<ll> hatao;
				for(auto x: m2){
					//cout<<i<<" "<<x.first<<" "<<x.second<<endl;
					if(x.first > i){ break;}
					m[x.second] = *(id[x.second].upper_bound(i));
					//cout<<x.second<<" "<<m[x.second]<<" new"<<endl;
					m2[m[x.second]] = x.second;
					hatao.push_back(x.first);
					//m2.erase(x.first);
				}
				for(int i=0; i<hatao.size(); i++){
					m2.erase(hatao[i]);	
				}
				//cout<<"here";
				auto pt = --m2.end();
				m.erase(pt->second);
				m2.erase(pt->first);
			}
			//cout<<*(id[a[i]].upper_bound(i))<<" ";
			//cout<<i<<" "<<m2.count(*(id[a[i]].upper_bound(i)))<<endl;
			m[a[i]] = *(id[a[i]].upper_bound(i));
			m2[m[a[i]]] = a[i];
		}
	}
	cout<<ans;
}