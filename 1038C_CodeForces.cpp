#include <iostream>
#include <algorithm>

using namespace std;
#define F(a,n) for(int i=1; i<=n; i++){cin>>a[i];}

int main(){
	int n;
	int a[100009], b[100009];
	cin>>n;
	a[0] = -1;
	b[0] = -1;

	F(a,n);
	F(b,n);

	sort(a, a+n+1);
	sort(b, b+n+1);
	int pt_a = n, pt_b = n;
	int i=0;
	long ans =0;

	while(pt_a > 0 && pt_b > 0){
		if(i%2==0){
			if(b[pt_b] > a[pt_a]){
				pt_b--;
			}
			else{
				ans += a[pt_a];
				pt_a--;
			}
		}
		else{
			if(a[pt_a] > b[pt_b]){
				pt_a--;
			}
			else{
				ans -= b[pt_b];
				pt_b--;
			}
		}
		i++;
	}
	//cout<<ans<<" "<<i<<" "<<pt_a<<" "<<pt_b<<endl;
	int* left = pt_b==0? &a[pt_a]: &b[pt_b];
	if(pt_b==0){
		while(*left != -1){
			//cout<<i<<" "<<*left<<endl;
			if(i%2==0){
				ans += *left;
				left--;
			}
			else{
				left--;
			}
			i++;
		}
	}
	else{
		while(*left != -1){
			//cout<<i<<" "<<*left<<endl;
			if(i%2!=0){
				ans -= *left;
				left--;
			}
			else{
				left--;
			}
			i++;
		}
	}
	cout<<ans;

}