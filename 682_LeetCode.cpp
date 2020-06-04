#include <bits/stdc++.h>

using namespace std;

#define ll long long

int calPoints(vector<string>& ops) {
    stack<int> s;
    for(auto x:ops){
    	cout<<"here "<<x<<endl;
    	if(isdigit((char)x[0]) || x[0] == '-'){
    		stringstream w(x);
    		int p=0;
    		w>>p;
    		s.push(p);
    	}
    	else if(x[0] == 'C'){
    		s.pop();
    	}
    	else if(x[0] == 'D'){
    		s.push(2*s.top());
    	}
    	else if(x[0] == '+'){
    		int temp = s.top();
    		s.pop();
    		int next = temp + s.top();
    		s.push(temp);
    		s.push(next);
    	}
    	cout<<s.top()<<endl;
    }
    int ans=0;
    while(!s.empty()){
    	ans += s.top();
    	s.pop();
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
	vector<string> v{"1","C","-62","-45","-68"};
	cout<<"here*"<<endl;
	cout<<calPoints(v);
	
}