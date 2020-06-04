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

//we will create disjoint set for all possible group
//first we will combine set of the (ith) and (n-ith) beacuse the string must be palindrome
//then we will combine the ith and (i+k)th number 
//we will find the size of each set and subtract the frequency of the maximum occuring character
//the idea is to change minimum number of character in a set
//hence we keep the most frequenct char and change rest (ie. change value of others to the value of most frequent char) 
// combine(S[i],  S[n-i-i]) and combine(S[i], S[i+k])

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

//c is the frequency array for each letter in each set
int c[200005][26]={0};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n, k;
		string s;
		cin>>n>>k;
		cin>>s;
		dsu st(n);
		//combining S[i] and S[n-i-i], palindromic condition
		for(int i=0; i<=(n-1)/2; i++){
			st.union_set(i, n-i-1);
		}
		//combining S[i] and S[i+k], other condition
		for(int i=0; i<n-k; i++){
			st.union_set(i, i+k);	
		}

		for(ll i = 0 ; i < n ; i++)
			for(ll j = 0 ; j < 26 ; j++)
				c[i][j] = 0;

		//markking the frequency of letters in each set
		for(ll i = 0 ; i<n ; i++){
			c[st.get(i)][s[i]-'a']++;
		}
		//stroes the final answer
		int ans=0;
		for(int i=0; i<n; i++){
			if(st.get(i) == i){// if i is a leader
				int total=0;//stores total number of element in a set with leader as i
				int max_freq=0;
				for(int j=0; j<26; j++){
					total += c[i][j];
					max_freq = max(max_freq, c[i][j]);
				}
				ans += (total - max_freq);
			}
		}
		cout<<ans<<"\n";
	}
	
}