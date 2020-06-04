#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, pair<int, int>> a,pair<int, pair<int, int>> b){
	return a.first < b. first;
}

int main(){
	set<pair<int, int> > asc, dsc;
	int n, a, b;
	for(int i=0; i<n; i++){
		cin>>a>>b;
		if(a>b){
			asc.insert(make_pair(b, i));
		}
		else{
			dsc.insert(make_pair(b, i));
		}
	}
}