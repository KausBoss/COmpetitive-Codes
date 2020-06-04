#include <iostream>
#include <bitset>
using namespace std;
#define inf 100001


void func(){
	int a[inf], temp, n;
	bitset<inf> pos;
	bitset<inf> neg;
	int pos_aya=0, neg_aya=0;
	cin>>n;
	for(int i=0; i<n; i++){
		if(pos_aya){pos[i]=1;}
		if(neg_aya){neg[i]=1;}
		cin>>a[i];
		if(a[i]==1){pos_aya=1;}
		if(a[i]==-1){neg_aya=1;}
	}
	for(int i=0;i<n; i++){
		cin>>temp;
		a[i] = temp-a[i];
	}
	for(int i=0; i<n; i++){
		if(a[i] > 0){
			if(pos[i]==0){
				cout<<"NO"<<"\n";
				return;
			}
		}
		if(a[i] < 0){
			if(neg[i]==0){
				cout<<"NO"<<"\n";
				return;
			}
		}
	}
	cout<<"YES"<<"\n";
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		func();
	}
}