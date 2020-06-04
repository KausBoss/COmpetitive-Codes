#include <iostream>
#include <math.h>

using namespace std;

int Coins(int n) {
    if(n ==0 || n==1){
        return n;
    }
    if(n == 2){
        return 3;
    }
    int s = 2;
    int e = sqrt(3*n);
    
    int ans =0;
    while(s <= e){
        int mid = (s+e)/2;
        int sum = ((mid+1)*mid)/2;
        //cout<<mid<<" "<<sum<<endl;
        cout<<s<<" "<<e<<endl;	
        if(sum == n){
            return mid;
        }
        if(sum < n){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid -1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<Coins(n)<<endl;
}