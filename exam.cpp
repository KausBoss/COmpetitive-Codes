#include <iostream>
#include <vector>

using namespace std;

int ans =-1;

bool possible(vector<int> day, vector<int> exam, int dead_line, int total_exam){
	int prep=0;
	//cout<<"for "<<dead_line<<": ";
	for(int i=0 ; i<dead_line; i++){
		//cout<<prep<<" ";
		if(day[i]==0){
			prep++;
		}
		else{
			int required_days = exam[day[i]-1];
			if(required_days == -1){
				continue;
			}
			if(required_days <= prep){
				//cout<<"days needed "<<required_days<<" less than "<<prep<<" making one less "<<total_exam<<endl;
				prep -= required_days;
				exam[day[i]-1] = -1;
				total_exam--;
			}
			else{
				prep++;
			}
		}
	}
	if(total_exam==0){
		return true;
	}
	return false;
}

void binary(vector<int> day, vector<int> exam, int s, int e, int total_exam){
	//cout<<"doing "<<s<<" "<<(s+e)/2<<" "<<e<<endl;
	//base case
	if(s>e){
		return;
	}
	//recursive case
	int mid = (s+e)/2;
	if(possible(day, exam, mid, total_exam)){
		ans = mid;
		//cout<<"possible for "<<mid<<endl;
		binary(day, exam, s, mid-1, total_exam);
	}
	else{
		binary(day, exam, mid+1, e, total_exam);
	}
}


int main(){
	int temp, total_days, total_exam;
	vector<int> day, exam;
	cin>>total_days>>total_exam;
	for(int i=0; i<total_days; i++){
		cin>>temp;
		day.push_back(temp);
	}
	for(int i=0; i<total_exam; i++){
		cin>>temp;
		exam.push_back(temp);
	}

	binary(day, exam, 0, total_days, total_exam);

	cout<<ans;
}