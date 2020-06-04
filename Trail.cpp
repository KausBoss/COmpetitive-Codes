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
	vector<vector<int>> v(4, vector<int> (3, 7));

	for(auto i:v){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}