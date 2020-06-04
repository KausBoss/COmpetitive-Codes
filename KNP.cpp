#include <iostream>
#include <cstring>

using namespace std;

int table[10000]={0};

void CalculateTable(string p){
	int i=1;
	int j=0;
	int lp = p.length();
	while(i<lp){

		while(j>0 && p[i]!=p[j]){
			j = table[j-1];
		}

		if(p[i] == p[j]){
			table[i] = j+1;
			i++;
			j++;
		}
		else{
			i++;
		}

	}
}

void KMP(string s,string p){
	CalculateTable(p);

	int i=0,j=0;
	int ls = s.length();
	int lp = p.length();

	while(i<ls){

		while(j>0 && s[i] != p[j]){
			j = table[j-1];
		}

		if(s[i] == p[j]){
			i++;
			j++;
		}
		else{
			i++;
		}
		if(j == lp){
			cout<<i-j<<endl;
			j = table[j-1];
		}
	}

}
int main(){
	string s, p;
	int n;
	cin>>n;
	cin>>p>>s;
	KMP(s,p);
}