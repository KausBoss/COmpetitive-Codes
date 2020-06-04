#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int k, x, ans=0;
		char s[10004];
		int freq[26]={0};
		cin>>s;
		cin>>k>>x;
		for(int i=0; s[i]!='\0'; i++){
			int idx = s[i] - 'a' ;
			//cout<<idx<<" "<<ans<<" "<<s[i]<<" "<<k<<endl;
			if(freq[idx] == x){
				if(k>0){
					k--;
				}
				else{
					break;
				}
			}
			if(freq[idx] < x){
				freq[idx]++;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}