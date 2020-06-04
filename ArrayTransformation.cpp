#include <iostream>
#include <vector>
#include <climits>
#include <cmath> 

using namespace std;

int main(){
	vector<int> vec;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		vec.push_back(temp);
	}
	int max_num=INT_MIN, min_num=INT_MAX; 
	for(int i=1; i<n-1; i++){
		min_num = min(min_num, vec[i]);
		max_num = max(max_num, vec[i]);
	}

	float ret = (max_num - min_num);
	ret = ret/2;
	cout<<ceil(ret)<<endl;
}