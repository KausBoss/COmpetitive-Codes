#include <iostream>
#include <set>

using namespace std;

#define ll long long

set <string> ans;

bool fun(string a, string b){
	return (a<b);
}

bool possible(char ch[], int j){
	for(int i=j+1; ch[i]!='\0'; i++){
		if(ch[i] == ch[j]){
			return false;
		}
	}
	return true;
}

void tricky(char ch[], int i){
	//base case
	if(ch[i] == '\0'){
		ans.insert(ch);
		return;
	}
	//recursive case
	tricky(ch, i+1);
	for(int j=i+1; ch[j]!='\0'; j++){
		if(ch[j]!=ch[i]){
			if(possible(ch, j)){
				swap(ch[i], ch[j]);
				tricky(ch, i+1);
				swap(ch[i], ch[j]);
			}
		}
	}
}


int main(){
	int t;
	cin>>t;
	while(t--){
		ll n, k;
		cin>>n>>k;
		char ch[100000];
		ch[0] = ch [1]= 'b';
		for(int i=2; i<n; i++){
			ch[i] = 'a';
		}
		ch[n] = '\0';
		tricky(ch, 0);
		for(auto x:ans){
			if(k==1){
				cout<<x<<endl;
				break;
			}
			k--;
		}  
		ans.clear();
	}
}