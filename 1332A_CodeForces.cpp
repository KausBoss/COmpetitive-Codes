#include <iostream>

using namespace std;

#define ll long long

int main(){
	ll t, xmax, xmin, ymax, ymin, xcur, ycur, a, b, c, d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		cin>>xcur>>ycur>>xmin>>ymin>>xmax>>ymax;
		if(xmin == xmax){
			if(a>0 || b>0){
				cout<<"No"<<endl;
				continue;
			}
		}
		if(ymin == ymax){
			if(c>0 || d>0){
				cout<<"No"<<endl;
				continue;
			}
		}
		ll xfin = (xcur-a+b);
		ll yfin = (ycur-c+d);
		if(xmin<=xfin&&xfin<=xmax&&ymin<=yfin&&yfin<=ymax){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
}