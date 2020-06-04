#include <iostream>
#include <climits>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, a[100];
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		int last=-1;
		bool flag = false;
		for(int i=0; i<n; i++){
			if(a[i] == 1){
				if(last == -1){
					last = i;
					continue;
				}
				if(i - last < 6){
					cout<<"NO"<<endl;
					flag = true;
					break;
				}
				else{
					last = i;
				}
			}
		}
		if(!flag){
			cout<<"YES"<<endl;
		}
	}
}