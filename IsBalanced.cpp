#include <bits/stdc++.h>

using namespace std;

int open_square=0, close_square=0, open_curly=0, close_curly=0, open_round=0, close_round=0;

bool bracket(char *ch, int i){
	//base case
	if(ch[i] == '\0'){
		if(open_square==close_square && open_curly==close_curly && open_round==close_round){
			return true;
		}
		return false;
	}
	//recursive case
	if(ch[i]=='['){open_square++;} 
	if(ch[i]=='{'){open_curly++;} 
	if(ch[i]=='('){open_round++;}

	if(ch[i]==']'){close_square++;} 
	if(ch[i]=='}'){close_curly++;} 
	if(ch[i]==')'){close_round++;}

	if(open_square<close_square || open_curly<close_curly || open_round<close_round){
		return false;
	}
	//cout<<open_square<<"--"<<close_square<<"--"<<open_curly<<"--"<<close_curly<<"--"<<open_round<<"--"<<close_round<<endl;
	return bracket(ch, i+1);
}

int main(){
	char ch[1000];
	cin>>ch;
	if(bracket(ch,0)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
}