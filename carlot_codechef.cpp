#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int m, n, lev=0;
		cin>>m>>n;
		char ar[m][n];
		int c = -98;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cin>>ar[i][j];
				if(ar[i][j] == 'P' && c == -98){
					c = j;
					lev = i;
				}
			}
		}
		vector <pair<int, int> > a;
		for(int i=0; i<m; i++){
			int left = -1, right =-1;
			for(int j=0; j<n; j++){
				if(ar[i][j]== 'P'){
					left = j;
					break;
				}
			}
			for(int j=n-1; j>=0; j--){
				if(ar[i][j]=='P'){
					right = j;
					break;
				}
			}
			a.push_back(make_pair(left, right));
		}
		int neeche=0;
		for(int i=m-1; i>=0; i--){
			if(a[i].first!=-1){
				neeche = i;
				break;
			}
		}
		//cout<<"->"<<neeche<<" ";
		int steps=0;
		for(int i=lev; i<=neeche; i++){
			if(i == neeche){
				if((i)%2==0){
					steps+= a[i].second - c;
					break;
				}
				else{
					steps += c - a[i].first;
					break;
				}
			}

			if(i%2==0){
				if(a[i].first!=-1){
					steps += a[i].second - c;
					c = a[i].second;
				}	
				if(a[i+1].second > c && c!=-1){
					steps += a[i+1].second - a[i].second +1;
					c = a[i+1].second;
				}
				else{
					steps++;
				}
			}
			if(i%2!=0){
				if(a[i].first!=-1){
					steps += c - a[i].first;
					c = a[i].first;
				}
				if(a[i+1].first!=-1 && a[i+1].first < c){
					steps+= a[i].first - a[i+1].first +1;
					c = a[i+1].first;
				}
				else{
					steps++;
				}
			}
		}
		cout<<steps<<endl;
		a.clear();
	}
}