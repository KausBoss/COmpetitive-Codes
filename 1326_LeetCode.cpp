#include <bits/stdc++.h>

using namespace std;

 int minTaps(int N, vector<int>& ranges) {
    int n=ranges.size();
   	vector<pair<int,int>> v;
   	for(int i=0; i<n; i++){
        if(ranges[i]!=0){
            v.push_back({i - ranges[i], i + ranges[i]});   
        }
   	}
   	sort(v.begin(), v.end());
   	int ans=0, pos=0, limit=0;
    n = v.size();
   	for(int i=0; i<n; i++){
   		if(v[i].first > pos){
   			if(limit == pos){
   				return -1;
   			}
   			pos = limit;
   			ans++;
   			i--;
   		}
   		else{
   			limit = max(limit, v[i].second);
   		}
   		if(pos >= N){
   			return ans;
   		}
   	}
    if(pos < limit){pos=limit; ans++;}
   	return pos>=N ? ans : -1;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    vector<int> r{1,2,1,0,2,1,0,1};
    int n=7;
    cout<<minTaps(n, r);
}