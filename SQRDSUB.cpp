#include <iostream>
using namespace std;
#define ll signed long long
#define inf 100005

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int a[inf];
		ll n, temp;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>temp;
			a[i]= abs(temp%4);
		}
		ll left=0, beech=-1, count =0, total = (n*(n+1))/2;
		for(int i=0; i<n; i++){
			//cout<<a[i]<<"--";
			if(a[i]==2){
				if(beech==-1){
					beech=i; 
				}
				else{
					count+= (beech-left+1)*(i-beech);
					left = beech+1;
					beech =i;
				}
			}
			if(a[i]==0){
				if(beech==-1){
					left = i+1;
				}
				else{
					count = count + ((1 + beech- left)*(i-beech));
					left = i+1;
					beech=-1;
				}
			}
		}
		if(beech!=-1){
			count+= (beech-left+1)*(n-beech);
		}
		total -= count;
		cout<<total<<"\n";
	}
}