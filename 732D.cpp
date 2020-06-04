#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 


bool possible(int n, int m,const vector<int> ExmD[], int *prep, int dday){
	vector<pair<int, int>> x;

	for(int i=1; i<=m; i++){
		auto it = upper_bound(ExmD[i].begin(), ExmD[i].end(), dday);
		if(it == ExmD[i].begin()){return false;}
		x.push_back(make_pair(*(--it), i));
	}

	sort(x.begin(), x.end());

	int buffer =0, earlier =0, prepneed =0, exam_day = 0, available_day =0;

	for(auto y:x){
		exam_day = y.first;
		prepneed = prep[y.second] + 1;
		available_day = exam_day - earlier + buffer;
		if(prepneed > available_day){
			return false;
		}
		buffer = available_day - prepneed;
		earlier = exam_day;
	}
	return true;
}



int Exam(int n, int m,const vector<int> ExmD[], int *prep){
	int s=1;
	int e=n+1;
	int ans = -1;
	while(s<e){
		int mid = (s+e)/2;
		if(possible(n, m, ExmD, prep, mid)){
			ans = mid;
			e = mid;
		}
		else{
			s = mid +1;
		}
	}
	return ans;
}


int main(){
	int n,m;
	cin>>n>>m;
	int *d = new int[n+1];
	vector<int> ExmD[100002];


	for(int i=1; i<=n; i++){
		cin>>d[i];
		if(d[i]==0){
			continue;
		}
		else{
			ExmD[d[i]].push_back(i);
		}
	}
	int *prep = new int [m+1];
	for(int i=1; i<=m; i++){
		cin>>prep[i];
	}

	cout<<Exam(n, m, ExmD, prep)<<endl;

}