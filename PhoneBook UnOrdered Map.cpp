#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
	unordered_map <string, vector<string>> phone_book;
	phone_book["kaustubh"].push_back("8130500788");
	phone_book["kaustubh"].push_back("9868751803");
	phone_book["reena"].push_back("9911241803");
	phone_book["reena"].push_back("8800212788");

	for(auto x:phone_book){
		cout<<"Name : "<<x.first<<" : ";
		for(string s:x.second){
			cout<<s<<", ";
		}
		cout<<endl;
	}

}