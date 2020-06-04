#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

class student{
public:
	string first_name;
	string last_name;
	int roll_no;
	student(string f, string l, int r){
		this->first_name = f;
		this->last_name = l;
		this->roll_no = r;
	}
	bool operator==(const student &s) const{
		return (roll_no == s.roll_no)?true:false;
	}
};

class Hasher{
public:
	size_t operator()(const student &s) const{
		return s.roll_no;
	}
};

int main(){
	unordered_map <student, int, Hasher> um;
	student s1("kaustubh","tripathi",21);
	student s2("vivek","tripathi",11);
	student s3("kashika","tripathi",31);
	student s4("reena","tripathi",01);

	um[s1] = 100;
	um[s2] = 20;
	um[s3] = 55;
	um[s4] = 70;

    for(auto m:um){
        cout<<m.first.first_name<<" "<<m.second<<endl;
    }

}