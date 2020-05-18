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

bool isMatch(string s, string p) {
    int pl=p.length();
    int sl=s.length();
    s = " "+s;
    p = " "+p;

    vector<vector<bool>> dp(pl+1, vector<bool>(sl+1, 0));
    dp[0][0]=1;
    for(int i=2; i<=pl; i++){
    	if(p[i]=='*'){
    		dp[i][0]=dp[i-2][0];
    	}
    }

    for(int i=1; i<=pl; i++){
    	for(int j=1; j<=sl; j++){
    		if(p[i] == s[j] || p[i] == '.'){
    			dp[i][j] = dp[i-1][j-1];
    		}
    		if(p[i] == '*'){
    			dp[i][j] = (dp[i-1][j] || dp[i-2][j] || (dp[i][j-1]&&p[i-1]=='.') || (dp[i][j-1]&&(p[i-1]==s[j])));
    		}
    	}
    }
    for(int i=0; i<=pl; i++){
    	cout<<p[i]<<" ";
    	for(int j=0; j<=sl; j++){
    		cout<<dp[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return dp[pl][sl];
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s="aab";
	string p="c*a*b";
	cout<<"    ";
	for(auto x:s){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<isMatch(s, p);
}

