#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pob pop_back
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
const int mod = 2520;
string s;
ll dp[13][2520][515];

// bool poss(ll sum, ll mask){
// 	for(int i=0; i<9; i++){
// 		if((mask&(1<<i))>0 && sum%(i+1)!=0){
// 			return false;
// 		}
// 	}
// 	return true;
// }

ll powmod(ll a,ll b)
{
	ll x=1,y=a;
	while(b>0)
	{
		if(b%2)
			x=(x*y)%mod;
		y=(y*y)%mod;
		b=b/2;
	}
	return x;
}

ll func(ll pos, bool tight, ll sum, ll mask){
	//base case
	if(pos == s.length()){
			for(int i=0; i<9; i++){
			if((mask&(1<<i))>0 && sum%(i+1)!=0){
				return 0;
			}
		}
		return 1;
	}
	//recursive case
	if(!tight && dp[pos][sum][mask]!=-1){ return dp[pos][sum][mask];}

	ll ans=0;
	ll end = tight ? s[pos]-'0' : 9;
	bool already= false;

	for(ll i=0; i<=end; i++){
		ll val= (i==0)? 0 : powmod(i,i);
		ll m2 = (i==0) ? mask : (mask|(1<<(i-1)));
		ans += func(pos+1, (tight)&(i==end), (sum+val)%mod, m2);
	}
	if(!tight){
		dp[pos][sum][mask] = ans;
	}
	return ans;
}


// void solve(){
// 	ll a, b;
// 	cin>>a>>b;
// 	memset(dp, -1, sizeof(dp));
// 	s = to_string(b);
// 	ll ans = func(0, 1, 0, 0);

// 	a--;
// 	memset(dp, -1, sizeof(dp));
// 	s = to_string(a);
// 	ans -= func(0, 1, 0, 0);

// 	cout<<ans<<endl;
// }


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		ll a, b;
		cin>>a>>b;
		memset(dp, -1, sizeof(dp));
		s = to_string(b);
		ll ans = func(0, 1, 0, 0);

		a--;
		memset(dp, -1, sizeof(dp));
		s = to_string(a);
		ans -= func(0, 1, 0, 0);

		cout<<ans<<endl;
	}
}