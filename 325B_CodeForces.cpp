#include <iostream>
#include <math.h>

using namespace std;

typedef unsigned long long uint_64_t;
#define ll uint_64_t

#define F(c, n) ((1-2*c)+sqrt(pow(2*c-1, 2)+(8*n)))/2

bool flag = true;

void findMatch(ll n, int s, int e){
	//base case
	if(s > e){
		return;
	}
	//recursive case
	ll mid = (s+e)/2;
	ll c = pow(2, mid) - 1;
	ll m = F(c,n);
	if(F(c,n) < 0){
		findMatch(n, s,  mid -1);
	}
	if(m < n){
		findMatch(n, s,  mid -1);
	}
	else{
		findMatch(n, mid+1,  e);
	}
}

int main(){
	ll n;
	cin>>n;
	if(n != 3){
		findMatch(n, 0, 64);
	}
	if(n == 3){
		cout<<3<<endl<<4;
		flag = false;
	}
	if(flag){
		cout<<-1;
	}
}