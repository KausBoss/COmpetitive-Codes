#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		if(a < 10 && b < 10){
			cout<<a+b<<endl;
			continue;
		}
		if(a<10 && b > 9){
			if(a > b/10){
				cout<<(a*10+b%10)+(b/10)<<endl;
			}
			else{
				cout<<"here1";
				cout<<a+b<<endl;
			}
		}
		if(b<10 && a > 9){
			if(b > a/10){
				cout<<(b*10+a%10)+(a/10)<<endl;
			}
			else{
				cout<<"here2";
				cout<<a+b<<endl;
			}
		}
		if(a > 9 && b > 9){
			int bada = max(a, b);
			int chotu = min(a, b);
			if(floor(bada/10) > chotu%10){
				if(floor(chotu/10) < bada%10){
					cout<<(bada/10)*10+floor(chotu/10) + (bada%10)*10+chotu%10<<endl;
				}
				else{
					cout<<"here3";
					cout<<bada+chotu<<endl;
				}
			}
			else{
				cout<<((chotu%10)*10 + bada%10)+(floor(chotu/10)*10+floor(bada/10))<<endl;
			}
		}
	}
}