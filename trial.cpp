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
	ll n, m;
	cin>>n>>m;
	vector<ll> a(n);
	vector<ll> freq(m+1, 0);
	for(int i=0; i<n; i++){
		cin>>a[i];
		if(a[i] <= m){
			freq[a[i]]++;
		}
	}
	priority_queue<pair<ll,ll> , vector<pair<ll,ll>>, greater<pair<ll,ll>>> p;

	for(int i=1; i<=m; i++){
		p.push({freq[i], i});
	}
	int change=0;
	int avg = ceil((float)n/m);
	int lb = floor((float)n/m);

	for(int i=0; i<n; i++){
		if(p.top().fi >= lb){
			break;
		}
		if(a[i]>m){
			change++;
			pair<ll, ll> temp=p.top();
			p.pop();
			a[i]=temp.si;
			freq[temp.si]++;
			p.push({temp.fi+1, temp.si});
		}
		else if(freq[a[i]] > avg){
			P(freq, m);
			freq[a[i]]--;
			change++;
			pair<ll, ll> temp=p.top();
			p.pop();
			a[i]=temp.si;
			freq[temp.si]++;
			p.push({temp.fi+1, temp.si});
		}
	}
	P(freq, m);
	cout<<p.top().fi<<" "<<change<<endl;
	P(a, n);
}