#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		set<char> sett;
		cin>>s;
		int len = s.length();
		for(int i=0; i<len; i++){
			if(s[i] == s[i+1] && i!=len-1){
				i++;
			}
			else{
				sett.insert(s[i]);
			}
		}
		if(sett.size() == 0){
			cout<<endl;
		}
		else{
			for(char i:sett){ 
				cout<<i;
			}
			cout<<endl;
		}
		sett.clear();
	}
}