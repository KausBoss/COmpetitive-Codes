#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
using namespace std;

#define F(a,x) for(int i=1; i<=x;i++){cout<<a[i]<<"**";}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k, m;
		int a[51][51]={0};
		int freq[10] = {0};
		cin>>n>>m>>k;
		for(int i=0; i<k; i++){
			for(int j=0; j<n; j++){
				cin>>a[j][i];
			}
		}
		for(int i=0 ;i<n; i++){
			memset(freq, 0, sizeof(freq));
			for(int j=0; j<k; j++){
				freq[a[i][j]]++;
			}
			//F(freq,m);
			//cout<<endl;
			int max = 0;
			freq[0] = INT_MIN;
			for(int w=1; w<=m; w++){
				//cout<<"here "<<max<<" "<<freq[w]<<"()()";
				if(freq[w] > freq[max]){
					//cout<<"here "<<max<<" "<<w<<"==";
					max = w;
				}
			}
			cout<<max<<" ";
		}
		cout<<"\n";
	}
}