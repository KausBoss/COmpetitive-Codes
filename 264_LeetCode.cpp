#include <bits/stdc++.h>

using namespace std;

#define ll long long

int nthUglyNumber(int n) {
   int i=0;
   int j=0;
   int k=0;
   vector<int> v;
   v.push_back(1);
   while(v.size() < n){
   	int mini= min(v[i]*2, min(v[j]*3, v[k]*5));
   	if(v[i]*2 == mini){i++;}
   	if(v[j]*3 == mini){j++;}
   	if(v[k]*5 == mini){k++;}
   	v.push_back(mini);
   }
   return v.back();
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cout<<nthUglyNumber(100);
}