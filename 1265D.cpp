#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e4+5;
const int mod = 1e9+7;

void func(){
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	if(c == 0 && d== 0){
		if(abs(b-a) > 1) { cout<<"NO"; return;}
		int times = min(a, b);
		deque<int> ab;
		while(times){
			ab.push_back(0);
			ab.push_back(1);
			a--; b--;
			times--;
		}
		if(a){ab.push_back(0);}
		if(b){ab.push_front(1);}
		cout<<"YES"<<endl;
		while(!ab.empty()){
			cout<<ab.front()<<" ";
			ab.pop_front();
		}
		return;
	}

	if(a == 0 && b== 0){
		if(abs(d-c) > 1) { cout<<"NO"; return;}
		int times = min(c, d);
		deque<int> ab;
		while(times){
			ab.push_back(2);
			ab.push_back(3);
			c--; d--;
			times--;
		}
		if(c){ab.push_back(2);}
		if(d){ab.push_front(3);}
		cout<<"YES"<<endl;
		while(!ab.empty()){
			cout<<ab.front()<<" ";
			ab.pop_front();
		}
		return;
	}

	if(a>b || d>c || abs((b-a)-(c-d))>1){
		cout<<"NO";
		return;
	}
	cout<<"YES"<<endl;
	int n = a+b+c+d;
	deque<int> ab;
	while(a){
		ab.push_back(0);
		ab.push_back(1);
		a--; b--;
	}
	if((c-d)<b){ab.push_front(1); b--;}
	while(b){
		ab.push_back(2);
		ab.push_back(1);
		b--; c--;
	}
	while(d){
		ab.push_back(2);
		ab.push_back(3);
		d--; c--;
	}
	if(c){ab.push_back(2); c--;}
	while(!ab.empty()){
		cout<<ab.front()<<" ";
		ab.pop_front();
	}
	return;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	func();
}