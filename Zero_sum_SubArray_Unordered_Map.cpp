#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char const *argv[]){

	map <int, int> mapping;
	int n, sum=0;
	vector<int> arr, prefix;
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		arr.push_bacK(temp);
		sum += temp;
		prefix.push_bacK(make_pair(sum,i));
	}

}
