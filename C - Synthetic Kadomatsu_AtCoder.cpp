#include <bits/stdc++.h>

using namespace std;

#define ll long long
int A, B, C, n;
vector<int> arr(1000);
int ans=INT_MAX;

void func(int sumA, int sumB, int sumC, int i, vector<int> a, vector<int> b, vector<int> c){
	//base case
	if(i == n){
		if(!a.empty()&&!b.empty()&&!c.empty()){
			int total = (a.size()-1 + b.size()-1 + c.size()-1)*10;
			total += (abs(sumA - A) + abs(sumB - B) + abs(sumC - C));
			ans = min(total, ans);
		}		
		return;
	}
	//recursive case
	//case1.
	func(sumA, sumB, sumC, i+1, a, b, c);
	//case2.
	if(sumA < A){
		a.push_back(arr[i]);
		func(sumA+arr[i], sumB, sumC, i+1, a, b, c);
		a.pop_back();
	}
	//case3.
	if(sumB < B){
		b.push_back(arr[i]);
		func(sumA, sumB+arr[i], sumC, i+1, a, b, c);
		b.pop_back();
	}
	//case4.
	if(sumC < C){
		c.push_back(arr[i]);
		func(sumA, sumB, sumC+arr[i], i+1, a, b, c);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>A>>B>>C;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	vector<int> a,b,c;
	func(0, 0, 0, 0, a, b, c);
	cout<<ans;
}