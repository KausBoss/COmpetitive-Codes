#include <bits/stdc++.h>
#include <math.h>

using namespace std;

#define dd double
#define M_PI 3.14

dd lower_bound(dd b, dd c, dd s, dd e, dd &ans){
	if(s > e){
		return ans;
	}
	//recursive case
	dd mid = (s+e)/2;
	//cout<<setprecision(9)<<s<<"  "<<mid<<"  "<<e<<endl;
	float num1 = (2*mid+b)*sin(mid);
	float num2 = cos(mid)*(mid*mid+b*mid+c);
	float val = num1 - num2;
	if(val == 0.0000000){
		return mid;
	}
	if(val < 0){
		ans = mid;
		return lower_bound(b, c, mid, e, ans);
	}
	else{
		return lower_bound(b, c, s, mid, ans);
	}

}

int main(){
	int t;
	cin>>t;
	while(t--){
		dd b, c, ans = 0;
		cin>>b>>c;
		dd s = 1;
		dd e = (M_PI)/2;
		dd x = lower_bound(b, c, 0, (M_PI)/2, ans);
		dd fx = (x*x+b*x+c)/sin(x);
		cout<<setprecision(11)<< fx<<endl;
	}
}