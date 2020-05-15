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

vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    int n=B.size();
    sort(A.begin(),A.end());
    vector<pair<int,int>> b;
    for(int i=0; i<n; i++){
    	b.push_back({B[i],i});
    }
    sort(b.begin(), b.end());
    vector<int> x;
    vector<int> ans(n, -1);
    int j=0;
    for(int i=0; i<n; 1){
    	if(A[j] > b[i].first){
    		ans[b[i].second] = A[j++];
    		i++;
    	}
    	else{
    		x.push_back(A[j++]);
    	}
    	if(j == n){break;}
    }
    if(x.empty()){return ans;}
    j=0;
    for(int i=0; i<n; i++){
    	if(ans[i]== -1){
    		ans[i]=x[j++];
    	}
    	if(j==x.size()){return ans;}
    }
    return ans;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> a{12, 24, 8, 32};
	vector<int> b{13, 25, 32, 11};
	b = advantageCount(a, b);
	for(auto x:b){
		cout<<x<<" ";
	}
}

