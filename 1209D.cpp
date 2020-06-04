//use the nodes ans dishes and edges as guests
// we create disjoint components
// a single component of size c is at max capable of feeding c-1 guests 
//as the 1st guest will eat 2 dishes rest eat one
//use dsu to create disjoint components
// total satisfied guests = comp_size - 1 , for each component
// hence, comp_size1 -1 + compo_size2 - 1... comp_sizen -1 
//(comp_size1 to comp_sizen) == n
// and -1 occurs n times
//hence, satisfied guest-> n - c
//unsatisfied guests = k- (n-c)
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

class dsu{
	vector<ll> parent, rank;
	ll total_component;
public:
	dsu(int n){
		parent.resize(n+1);
		rank.resize(n+1);
		for(int i=1; i<=n; i++){
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
		a = get(a); //get leader of a
		b = get(b); //get leader of b
		if(a != b){
			//the leader with more rank will becaome the parent
			if(rank[a] < rank[b]){
				swap(a, b);//swapping if b has more rank than a
			}
			parent[b] = a;
			if(rank[a] == rank[b]){
				rank[a]++;
			}
			total_component--;
		}
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin>>n>>k;
	dsu g(n);
	for(int i=0; i<k; i++){
		int x, y;
		cin>>x>>y;
		g.union_set(x, y);
	}
	bool leader[n+1] = {0};
	for(int i=1; i<=n; i++){
		leader[g.get(i)]=true;
	}
	int c=0;
	for(int i=1; i<=n; i++){
		if(leader[i]){
			c++;
		}
	}
	cout<<k-(n-c)<<endl;
}