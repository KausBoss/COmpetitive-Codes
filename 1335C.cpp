#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, freq[300005]={0}, a, maxfreq=0;
		set<int> s;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a;
			freq[a]++;
			s.insert(a);
			maxfreq = max(freq[a], maxfreq);
		}
		int sz = s.size();
		s.clear();
		if(maxfreq<sz){
			cout<<maxfreq<<"\n";
			continue;
		}
		else if(maxfreq== sz){
			cout<<maxfreq-1<<"\n";
			continue;
		}
		else if(maxfreq > sz){
			cout<<sz<<"\n";
		}
	}
}	