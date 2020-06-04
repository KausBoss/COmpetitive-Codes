#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t, x, n, m;
	cin>>t;
	while(t--){
		cin>>x>>n>>m;
		//int ans = ((x + 20*(pow(20, n)-1))/(pow(2, n))) - 10*m;
		for(int i=0;  i<n && x>20; i++){
			x /= 2;
			x +=10;
		}
		x -= 10*m;
		//cout<<x<<"--";
		if(x <= 0){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}

}