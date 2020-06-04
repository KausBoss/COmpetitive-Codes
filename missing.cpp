#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
   
   for(int i=0;i<nums.size();i++)
   {
       int index=abs(nums[i])-1;
       if(nums[index]<0)
          continue;
       else
           nums[index]=-nums[index];
   }
    //Indexes where there are positive elements forms the answer. 
    vector<int>result;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>0)
            result.push_back(i+1);
    }
    return result;
}


int main(){
	
}