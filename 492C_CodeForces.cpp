#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define ll long long

bool comp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	vector<pair<int, int>> a;
	ll n, r, avg;
	cin>>n>>r>>avg;
	ll sum=0;
	for(int i=0; i<n; i++){
		ll a1, a2;
		cin>>a1>>a2;
		a.push_back(make_pair(a1, a2));
		sum += a1;
	}
	sort(a.begin(), a.end(), comp);
	ll needed = avg*n - sum;
	ll essay =0;int i=0;
	while(needed>0){
		if(a[i].first < r){
			if(r-a[i].first < needed){
				needed -= (r - a[i].first);
				essay += (r - a[i].first)*a[i].second;
				a[i].first = r;
			}
			else{
				essay += needed*a[i].second;
				break;
			}
		}
		i++;
	}
	cout<<essay;
}