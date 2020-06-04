#include <iostream>
#include <string>

using namespace std;

int main(){
	int t, a[9][9];
	cin>>t;
	while(t--){
		string s;
		for(int i=0; i<9; i++){
			cin>>s;
			for(int j=0; j<9; j++){
				a[i][j]=s[j]-'0';
			}
		}

		// for(int i=0; i<9; i++){
		// 	for(int j=0; j<9; j++){
		// 		cout<<a[i][j]<<"--";
		// 	}
		// 	cout<<"\n";
		// }


		for(int i=0; i<=6; i+=3){
			swap(a[i][i/3], a[i+1][(i/3)+3]);
			swap(a[i+1][(i/3)+3], a[i+2][(i/3)+6]);
		}

		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				cout<<a[i][j];
			}
			cout<<"\n";
		}
	}
}