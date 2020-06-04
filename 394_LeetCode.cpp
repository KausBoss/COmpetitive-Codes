#include <bits/stdc++.h>
using namespace std;
#define ll long long

void transfer(stack<char> &a, stack<char> &b){
	while(!a.empty()){
		b.push(a.top());
		a.pop();
	}
	return ;
}
void printTrans(stack<char> &a, stack<char> &b){
	while(!a.empty()){
		cout<<a.top()<<" ";
		b.push(a.top());
		a.pop();
	}
	cout<<endl;
	return ;
}

string decodeString(string S) {
	stack<char> s;
	//stack<char> aux;
	int freq;
	string temp="";

	for(auto x:S){
		//transfer(s, aux);
		//printTrans(aux, s);
		if(x==']'){
			while(s.top()!='['){
				temp += s.top();
				s.pop();
			}
			reverse(temp.begin(), temp.end());
			s.pop();
			string freeky="";
			while(!s.empty() && isdigit(s.top())){
				freeky+=s.top();
				s.pop();
			}
			int bit=1;
			for(auto q:freeky){
				freq += (q-'0')*bit;
				bit *=10;
			}
			string tt=temp;
			cout<<freq<<endl;
			while(freq>1){
				temp += tt;
				freq--;
			}
			for(auto w:temp){s.push(w);}
			temp="";
		}
		else{
			s.push(x);
		}
	}
	string ans="";
	while(!s.empty()){
		ans +=s.top();
		s.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s = "100[leetcode]";
	cout<<decodeString(s);
}