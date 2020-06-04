#include <iostream>
#include <math.h>
#include <map>
using namespace std;

int seive[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main(){
	int t, n, a[1000];
	cin>>t;
	while(t--){
		int ans[1000]= {0};
		map<int, int> uni;
		int maxm =0, unique=0, xo=0;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
			for(int j=0; seive[j]<=sqrt(a[i]); j++){
				int prime = seive[j];
				if(a[i]%prime==0){
					if(uni.count(prime)==1){
						ans[i] = uni[prime];
					}
					else{
						ans[i] = ++xo;
						uni.insert(make_pair(prime,xo));
					}
					break;
				}
			}
		}
		cout<<uni.size()<<"\n";
		for(int i=0; i<n; i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		uni.clear();
	}
}