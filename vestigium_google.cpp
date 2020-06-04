#include <iostream>
#include <map>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		int n, col=0, row=0, sum=0, t=0;
		cin>>n;
		int a[n][n];
		int total = (n*(n+1))/2;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>a[i][j];
			}
		}
		for(int i=0; i<n; i++){
			sum+=a[i][i];
		}
		for(int i=0; i<n; i++){
			map<int, int> m;
			for(int j=0; j<n; j++){
				int x = a[i][j];
				if(m.count(x)==1){
					row++;
					break;
				}
				else{
					m.insert(make_pair(x, x));
				}
			}
			m.clear();
		}

		for(int i=0; i<n; i++){
			map<int, int> m;
			for(int j=0; j<n; j++){
				int x = a[j][i];
				if(m.count(x)==1){
					col++;
					break;
				}
				else{
					m.insert(make_pair(x, x));
				}
			}
			m.clear();
		}
		cout<<"Case #"<<i<<": "<<sum<<" "<<row<<" "<<col<<endl;
	}
}