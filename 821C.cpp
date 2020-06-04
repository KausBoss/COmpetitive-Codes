#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, val, ans=0, ct=1;
	string st;
	stack<int> s;
	cin>>n;
	for(int i=0; i<2*n; i++){
		cin>>st;
		if(st == "remove"){
			if(s.empty()){ct++; continue;}
			else if(s.top() == ct){
				s.pop(); ct++;
			}
			else if(s.top() > ct){
				ans++;
				s = stack<int>();
				ct++;
			}
		}
		else{
			cin>>val;
			s.push(val);
		}
	}
	cout<<ans;
}