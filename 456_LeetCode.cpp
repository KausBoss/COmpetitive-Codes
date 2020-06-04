#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool find132pattern(vector<int> nums) {
	stack<int> s;
	for(int i=0; i<nums.size(); i++){
		if(s.empty()){
			s.push(nums[i]);
		}
		else{
			if(nums[i] > s.top()){
				s.push(nums[i]);
			}
			else if(nums[i]<s.top()){
				if(s.size()==1){
				 
				}
			}



			else if(nums[i]<s.top() && s.size()>1){
                int temp = s.top();
                s.pop();
                if(!s.empty() && s.top() < nums[i]){return true;}
                s.push(temp);
			}
			else if(nums[i]<s.top()){
				s.pop();
				s.push(nums[i]);
			}
		}
	}
    return false;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> v{-2,1,2,-2, 1, 2};
	cout<<find132pattern(v);
}