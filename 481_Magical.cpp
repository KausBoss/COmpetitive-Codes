#include <bits/stdc++.h>

using namespace std;

#define ll long long

int magicalString(int n) {
    int ans=0,id=2, num, t;
    if(n==0){return 0;}
    if(n<=3){return 1;}
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);

    while(a.size() < n){
    	num = (id%2)?2:1;
    	t=a[id++];
    	while(t--){
    		a.push_back(num);
    	}
    }
    for(int i=0; i<n; i++){
    	if(a[i]==1){ans++;}
    }

    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n=400;
	cout<<magicalString(n);
	
}

