#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e4+5;
const int mod = 1e9+7;

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	// ll n, c;
	// set<ll, greater<ll>> ones, ones2, twos, twos2;
	// ll tempw, tempc;
	// ll maxw=0;
	// cin>>n;
	// for(int i=0; i<n; i++){
	// 	cin>>tempw>>tempc;
	// 	if(tempw==1){
	// 		ones.insert(tempc);
	// 		ones2.insert(tempc);
	// 	}
	// 	else{
	// 		twos.insert(tempc);
	// 		twos2.insert(tempc);
	// 	}
	// 	maxw += tempw;
	// }

	// map<ll, ll> m;
	// m[1] = ones.empty() ? 0 : *ones.begin();
	// if(!ones.empty()){ ones.erase(m[1]); }

	// for(ll i=3; i<=maxw; i+=2){
	// 	ll adder;
	// 	if(ones.size() < 2){
	// 		adder = *twos.begin();
	// 		twos.erase(adder);
	// 	}
	// 	else{
	// 		ll one_1= *ones.begin();
	// 		ll one_2= *(++ones.begin());

	// 		if(one_1 + one_2 > *twos.begin()){
	// 			adder=one_1 + one_2;
	// 			ones.erase(one_1);
	// 			ones.erase(one_2);
	// 		}
	// 		else{
	// 			adder = *twos.begin();
	// 			twos.erase(adder);
	// 		}
	// 	}
	// 	m[i] = m[i-2] + adder;
	// }
	// ones2.erase(*ones2.begin());

	// if(!ones2.empty() && m[1] + *ones2.begin() > *twos2.begin()){
	// 	m[2] = m[1] + *ones2.begin();
	// 	ones2.erase(*ones2.begin());
	// } 
	// else if(m[1] > *twos2.begin()){
	// 	m[2] = m[1];
	// }
	// else {
	// 	m[2] = *twos2.begin();
	// 	twos2.erase(m[2]);
	// }

	// for(ll i=4; i<=maxw; i+=2){
	// 	ll adder;
	// 	if(ones2.empty() || ones2.size() < 2){
	// 		adder = *twos2.begin();
	// 		twos2.erase(adder);
	// 	}
	// 	else{
	// 		ll one_1= *ones2.begin();
	// 		ll one_2= *(++ones2.begin());

	// 		if(one_1 + one_2 > *twos2.begin()){
	// 			adder=one_1 + one_2;
	// 			ones2.erase(one_1);
	// 			ones2.erase(one_2);
	// 		}
	// 		else{
	// 			adder = *twos2.begin();
	// 			twos2.erase(adder);
	// 		}
	// 	}
	// 	m[i] = max(m[i-1], m[i-2] + adder);
	// }
	// for(auto x:m){
	// 	cout<<x.second<<" ";
	// }
	ll n, maxw=0, tempc, tempw;
	vector<ll> ones, twos;
	map<ll,ll> m;
	cin>>n;
	for(ll i=0; i<n; i++){
		cin>>tempw>>tempc;
		if(tempw==1){ ones.pb(tempc);}
		else{ twos.pb(tempc);}
		maxw += tempw;
	}

	sort(ones.begin(), ones.end());
	sort(twos.begin(), twos.end());

	ll op=ones.size(), tp=twos.size();
	ll val=0;
	for(ll i=2; i<=maxw; i+=2){
		ll val1=0, val2=0;
		if(tp>0){
			val2= twos[tp-1];
		}
		if(op>0){
			val1 = ones[op-1];
			if(op>1){
				val1 += ones[op-2];
			}
		}

		if(val2 > val1){
			val += val2;
			tp--;
		}
		else{
			val += val1;
			op -=2;
		}
		m[i]=val;
	}
	op=ones.size();
	tp=twos.size();
	val=0;

	if(op > 0){
		m[1] = ones[op-1];
		op--;
		val = m[1];
	}

	for(ll i=3; i<=maxw; i+=2){
		ll val1=0, val2=0;
		if(tp>0){
			val2= twos[tp-1];
		}
		if(op>0){
			val1 = ones[op-1];
			if(op>1){
				val1 += ones[op-2];
			}
		}

		if(val2 > val1){
			val += val2;
			tp--;
		}
		else{
			val += val1;
			op -=2;
		}
		m[i]=val;
	}

	for(ll i=1; i<=maxw; i++){
		cout<<m[i]<<" ";
	}
	return 0;
}