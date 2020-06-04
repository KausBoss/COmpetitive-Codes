#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n, a, b, c, d;
		cin>>n>>a>>b>>c>>d;
		int minw=n*(a-b);
		int maxw=n*(a+b);
		if(minw>(c+d) || maxw<(c-d)){
			cout<<"No\n";
		}
		else{
			cout<<"Yes\n";
		}
	}
}