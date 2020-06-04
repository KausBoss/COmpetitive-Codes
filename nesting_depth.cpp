#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0; i<n; i++){
		cout<<"Case #"<<i<<":";
		int cl=0;
		string s;
		cin>>s;
		for(int i=0; i<s.length(); i++){
			int x = s[i] - '0';
			if(x > cl){
				for(int j =0; j<(x-cl); j++){
					cout<<"(";
				}
				cout<<x;
			}
			if(x < cl){
				for(int j=0; j<cl-x; j++){
					cout<<")";
				}
				cout<<x;
			}
			if(x == cl){
				cout<<x;
			}
		}
		while(cl--){
			cout<<")";
		}
		cout<<endl;
	}
}