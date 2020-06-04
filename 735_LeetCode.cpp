#include <bits/stdc++.h>

using namespace std;

#define ll long long


vector<int> asteroidCollision(vector<int> a) {
	if(a.size()<=1){return a;}
    
	deque<int> s;
	for(int i=0; i<a.size(); i++){
		cout<<s.size()<<"**"<<a[i]<<endl;
		if(s.empty() || !(a[i]<0 && s.back()>0)){
			s.push_back(a[i]);
		}
		else if(a[i]<0 && s.back()>0){
			while(!s.empty() && s.back()>0){
				if(abs(a[i]) > s.back()){
					s.pop_back();
					if(s.empty()||s.back()<0)s.push_back(a[i]);
				}
				if(abs(a[i]) == s.back()){
					s.pop_back();
					break;
				}
				if(abs(a[i]) < s.back()){
					break;
				}
			}
		}
	}
	vector <int> ans;
	while(!s.empty()){
		ans.push_back(s.front());
		s.pop_front();
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
	vector<int> v{10, 2, -5};
	v = asteroidCollision(v);
	for(auto x:v){
		cout<<x<<" ";
	}
}