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
const int nax = 2e5+5;
const int mod = 1e9+7;
//we will perform the set unions according to the conditions given
// the final number of leaders is the ans or final number of disjoint set
// 

class dsu{
	vector<ll> parent, rank;
	ll total_component;
public:
	dsu(int n){
		parent.resize(n);
		rank.resize(n);
		for(int i=0; i<n; i++){
			parent[i] = i;
			rank[i] = 0;
		}
		total_component = n;
	}

	ll get(ll a){
		if(parent[a] == a){
			return a;
		}
		return parent[a] = get(parent[a]);
	}

	void union_set(ll a, ll b){
		a = get(a);
		b = get(b);
		if(a != b){
			if(rank[a] < rank[b]){
			}
			parent[b] = a;
			if(rank[a] == rank[b]){
				rank[a]++;
			}
			total_component--;
		}
	}
};

vector<string> a(nax);
int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		a[i] = s;
	}
	dsu g(26);

	for(int i=0; i<n; i++){
		//iterating on each string and making union of every char that occurs in it
		//with other
		for(int j=0; j<a[i].length()-1; j++){
			g.union_set(a[i][j]-'a', a[i][j+1]-'a');
		}
	}
	bool ct[26]={0}; //to mark the leaders
	int ans=0;

	for(int i=0; i<n; i++){
		for(int j=0; j<a[i].length(); j++){
			ct[g.get(a[i][j] - 'a')]=1; //incrementing the leader
		}
	}

	for(int i=0; i<26; i++){
		if(ct[i]){
			ans++;
		}
	}
	cout<<ans;
}