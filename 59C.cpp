#include <iostream>
#include <string>

int main(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	int len=s.length();
	for(int i=0; i<=n/2; i++){
		if(s[i]=='?'){
			if(s[n-i-1]=='?'){
				s[i]=s[n-i-1]='a';
			}
			else{
				s[i]= s[n-1-i];
			}
		}
		if(s[i]!=s[n-1-i] && s[i]!='?' && s[n-i-1]!='?'){
			cout<<"IMPOSSIBLE";
			flag= false;
			break;
		}
	}
	if(flag){
		cout<<s;
	}
}