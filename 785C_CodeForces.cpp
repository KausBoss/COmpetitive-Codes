#include<iostream>
#include <math.h>

using namespace std;

#define ll unsigned long long int

#define C(n,m) (m*m + m -2*n)

#define B(m) 1-2*m

#define F(a,b,c) (-b+sqrt(b*b - 4*a*c))/2

int main(){
	ll n, m, ans;
	cin>>n>>m;
	ans = ceil(F(1, B(m), C(n,m)));
	cout<<ans;
}