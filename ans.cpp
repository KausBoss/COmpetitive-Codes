#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		int cl=0;
		string s;
		cin>>s;
		cout<<"Case #"<<i<<": ";
		for(int i=0; i<s.length(); i++){
			int x = s[i] - '0';
			if(x > cl){
				for(int j =0; j<(x-cl); j++){
					cout<<"(";
				}
				cl=x; 
				cout<<x;
			}
			else if(x < cl){
				for(int j=0; j<cl-x; j++){
					cout<<")";
				}
				cl = x;
				cout<<x;
			}
			else if(x == cl){
				cout<<x;
			}
		}
		while(cl--){
			cout<<")";
		}
		cout<<endl;
	}
}