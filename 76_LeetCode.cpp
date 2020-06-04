#include <bits/stdc++.h>

using namespace std;

#define ll long long

string reorganizeString(string S) {
	map<char,int> m;
	int n=S.size();
	priority_queue<pair<int,char>> p;
	for(auto x:S){
		if(m.count(x)){m[x]++;}
		else{m[x]=1;}
		if(m[x] >= ((n/2)+1)){
			return "";
		}
	}
	for(auto x:m){
		p.push(make_pair(x.second, x.first));
	}
	string ans=S;
	int freq=p.top().first;
	for(int i=0; i<S.size(); i+=2){
		if(freq){
			ans[i]=p.top().second;
			freq--;
		}
		else{
			p.pop();
			freq=p.top().first;
			ans[i]=p.top().second;
			freq--;
		}
	}
	for(int i=1; i<S.size(); i+=2){
		if(freq){
			ans[i]=p.top().second;
			freq--;
		}
		else{
			p.pop();
			freq=p.top().first;
			ans[i]=p.top().second;
			freq--;
		}
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
	string s="aaab";
	cout<<reorganizeString(s);	
}