#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
	int t;
	cin>>t;
	while(t--){
		int r, c;
		cin>>r>>c;
		for(int i=0; i<r; i++){
			if(i%2==0){
				for(int j=0; j<c; j++){
					if((i==(r-1)) && (j==(c-2)) && ((r%2==0)||(c%2==0))){
						cout<<"BB";
						break;
					}
					if(j%2==0){
						cout<<"B";
					}
					else{
						cout<<"W";
					}
				}
			}
			if(i%2==1){
				for(int j=0; j<c; j++){
					if((i==(r-1)) && (j==(c-2)) && ((r%2==0)||(c%2==0))){
						cout<<"BB";
						break;
					}
					if(j%2==0){
						cout<<"W";
					}
					else{
						cout<<"B";
					}
				}
			}
			cout<<"\n";
		}
	}
}