#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool func(pair<int, pair<int, int> >  a, pair<int, pair<int, int>  > b){
	return a.second.first < b.second.first;
}

int main(){
	int t;
	cin>>t;
	for(int k=1; k<=t; k++){
		int n;
		vector<pair<int, pair<int, int> > > v;
		int js=0, je=0, cs=0, ce=0;
		cin>>n;
		for(int i=0; i<n; i++){
			int f,l;
			cin>>f>>l;
			v.push_back(make_pair(f, make_pair(l, i)));
		}
		sort(v.begin(), v.end(), func);
		cout<<"Case #"<<k<<": ";

		char ans[1002];bool flag = true;
		for(int i=0; i<v.size(); i++){
			if(ce > v[i].first && je > v[i].first){
				cout<<"IMPOSSIBLE"<<endl;
				flag = false;
				break;
			}
			if(ce <= v[i].first){
				cs = v[i].first;
				ce= v[i].second.first;
				ans[v[i].second.second]='C';
				continue;
			}
			if(je <= v[i].first){
				js = v[i].first;
				je = v[i].second.first;
				ans[v[i].second.second]='J';
				continue;
			}
		}

		if(flag){
			ans[n]='\0';
			cout<<ans<<endl;
		}
		v.clear();
	}
}