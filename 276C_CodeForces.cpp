#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int main(){
	int n, q;
	cin>>n>>q;
	long long a[200000];
	long long freq[200000] = {0};
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	int l, r;
	for(int i=0; i<q; i++){
		cin>>l>>r;
		freq[l-1]++;
		if(r < n){
			freq[r]--;
		}
	}
	for(int i=1; i<n; i++){
		freq[i] = freq[i] + freq[i-1];
	}
	sort(a, a+n);
	sort(freq, freq+n);
	long long sum=0;
	for(int i=0; i<n; i++){
		sum += a[i]*freq[i];
	}
	cout<<sum;
}