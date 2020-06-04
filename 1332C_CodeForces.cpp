#include <bits/stdc++.h>
#include <map>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k, ans =0;
		cin>>n>>k;
		string s;
		cin>>s;
		for(int i=0; i<k/2; i++){
			bool flag = false;
			int freq[26] = {0};
			for(int j = i; j<n; j=j+k){
				int a = s[j] - 'a';
				int b = s[k-j-1] - 'a';
				freq[a]++;
				freq[b]++;
			}
			int maxfreq=0;
			for(int x=0; 0<26; x++){
				if(freq[x] > 0){
					flag = true;
				}
				maxfreq = max(maxfreq, freq[x]);
			}
			if(k%2==1 && i ==floor(k/2) && flag){
				ans+= (2*n/k - maxfreq)/2;
			}
			if(i!=k/2 && flag){
				ans += 2*n/k - maxfreq;
			}
		}
		cout<<ans<<endl;
	}
}