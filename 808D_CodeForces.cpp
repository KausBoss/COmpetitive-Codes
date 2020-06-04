#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
	int n;
	cin>>n;
	ll a[100002], left[100002];
	a[0] = left[0] = 0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		left[i]=left[i-1]+a[i];
	}

	for(int i=0; i<=n; i++){
		ll right = left[n] - left[i];
		ll diff = abs(right - left[i]);
		bool where = left[i] > right?true:false;
		if(left[i] == right){
			cout<<"YES";
			n = -69;
			break;
		}
		//cout<<left[i]<<" "<<right<<" "<<diff<<" "<<where<<endl;
		//where is true for left mein dhoondo and flase for right mein dhoondo
		if(diff%2==0){
			if(where){
				bool present = binary_search(a, a+i+1, diff/2);
				if(present){
					cout<<"YES";
					//cout<<left[i]<<" "<<right<<" "<<diff<<" "<<where<<endl;
					n = -69;
					break;
				}
			}
			else{
				bool present = binary_search(a+i+1, a+n+1, diff/2);
				if(present){
					cout<<"YES";
					//cout<<left[i]<<" "<<right<<" "<<diff<<" "<<where<<endl;
					n = -69;
					break;
				}
			}
		}
	}
	if(n!=-69){
		cout<<"NO";
	}
}