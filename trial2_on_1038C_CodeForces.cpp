#include <iostream>
#include <algorithm>

using namespace std;
#define F(a,n) for(int i=0; i<n; i++){cin>>a[i];}

int main(){
	int n;
	int a[100009], b[100009];
	cin>>n;

	F(a,n);
	F(b,n);

	sort(a, a+n);
	sort(b, b+n);
	int pt_a =n-1, pt_b =n-1;
	int i=0;
	long ans =0;

	while()

	while(pt_a >= 0 && pt_b >= 0){
		if(i%2==0){
			if(b[pt_b] >= a[pt_a]){
				pt_b--;
			}
			else{
				ans += a[pt_a];
				pt_a--;
			}
		}
		else{
			if(a[pt_a] >= b[pt_b]){
				pt_a--;
			}
			else{
				ans -= b[pt_b];
				pt_b--;
			}
		}
		i++;
	}

	int ct = pt_b<0? pt_a: pt_b;

	if(pt_b < 0){
		while(ct >=0){
			if(i%2==0){
				ans+=a[ct];
			}
			ct--;
			i++;
		}
	}
	if(pt_a < 0){
		while(ct >=0){
			if(i%2!=0){
				ans-=b[ct];
			}
			ct--;
			i++;
		}
	}
	cout<<ans;
}