/*
DSU - disjoint set union
1. make_set - creates a set
2. Union - combines the leader of 2 sets
3. get - returns the leader of the set to which the node belongs
*/
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
	//parent stores the leader of each node
	// rank stores the size of the set to which a node belongs
	//total_component stores the number of disjoint set
	vector<ll> parent, rank;
	ll total_component;
public:
	dsu(int n){
		parent.resize(n);
		rank.resize(n);
		//initializing the parent and rank of each node
		// in the begining, parent of each node is the node itself
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
		return parent[a] = get(parent[a]); //get(parent[a]); -> this will get me the root node
	}

	void union_set(ll a, ll b){
		//we need to combine the leader of these two nodes
		a = get(a); //get leader of a
		b = get(b); //get leader of b
		//we will combine a and b only when they both have 
		//different leaders
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
	
}