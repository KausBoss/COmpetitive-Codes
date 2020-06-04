//Recursion-Codes of the string
#include <bits/stdc++.h>

using namespace std;

void print(char *ch, char *op, int i, int j){
	//base case
	if(ch[i]=='\0'){
		op[j]='\0';
		cout<<op<<", ";
		return;
	}
	//recusrive case
	int at_i=ch[i]-'0';
	int next= at_i*10+(ch[i+1]-'0');
	//cout<<i<<"--"<<at_i<<"--"<<next<<endl;
	op[j]=at_i+'a'-1;
	print(ch, op, i+1, j+1);
	if(next<=26&&ch[i+1]!='\0'){
		op[j]='a'+next-1;
		print(ch, op, i+2, j+1);
	}
}

int main(){
	char ch[1000], op[1000];
	cin>>ch;
	cout<<"[";
	print(ch, op, 0, 0);
	cout<<"]";
}