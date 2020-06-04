#include <iostream>
#include <string>

using namespace std;

int main(){
	int n, a, b;
	int t;
	cin>>t;
	while(t--){
		char ch= 'a';
		string s="";
		cin>>n>>a>>b;

		for(int i=0; i<b; i++){
			s += ch;
			ch++;
		}
		ch--;

		for(int i=b; i<a; i++){
			s += ch;
		}

		int i=n/s.length();
		int left = n%s.length();

		while(i--){
			cout<<s;
		}

		for(int i=0; i<left ; i++){
			cout<<s[i];
		}
		cout<<"\n";
		s.clear();
	}
}