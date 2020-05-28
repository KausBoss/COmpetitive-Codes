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

double val(ll n, ll h, ll c){
	double res = n*(h+c) + h;
	res /= ((2*n)+1);
	return res;
}

ll func(){
	ll h, c, t;
	cin>>h>>c>>t;
	double mi = (double)(h+c)/2;
	double a1= (double)(2*h + c)/3;
	if((double)t < mi){
		return 2;
	}
	if((double)t == mi){
		return 2;
	}
	if((double)t >= a1){
		if((double)abs(h-t) <=  (double)abs(t - a1)){
			return 1;
		}
		else{
			return 3;
		}
	}
	ll s = 1;
	ll e = 1e9;
	ll ans;
	while(s <= e){
		ll mid=(s+e)/2;
		//cout<<s<<" "<<mid<<" "<<e<<endl;
		if(val(mid, h, c) == (double)t){
			ans =mid;
			break;
		}
		else if(val(mid, h, c) < (double)t){
			e = mid-1;
			ans = mid;
		}
		else{
			s = mid+1;
		}
	}

	double less = abs(val(ans, h, c) - t);
	double more = abs(val(ans-1, h, c) - t);

	if(less < more){
		return (2*ans)+1;
	}
	return (2*(ans-1))+1;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		cout<<func()<<endl;
	}
}