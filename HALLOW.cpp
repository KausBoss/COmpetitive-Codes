#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, c;
	cin>>c>>n;
	while(c!=0 && n!=0){
		std::vector<int> v, freq(c, -1);
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			if(i == 0){
				v.push_back(x%c);
			}
			else{
				v.push_back((v.back()+x)%c);
			}
		}
		bool flag = true;
		for(int i=0; i<n; i++){
			if(freq[v[i]]!=-1){
				cout<<freq[v[i]]+1<<" "<<i+1<<endl;
				flag = false;
				break;
			}
			if(freq[v[i]]==-1){
				freq[v[i]]=i;
			}
		}
		if(flag){
			cout<<"no sweets"<<endl;
		}
		v.clear();freq.clear();
		cin>>c>>n;
	}
}