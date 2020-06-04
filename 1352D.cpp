#include <bits/stdc++.h>

using namespace std;

#define ll long long

void func(){
	int n;
	cin>>n;
	deque<int> q;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		q.push_back(temp);
	}
	int turn=1;
	int a=q.front(), b=0;
	int prev=a;
	q.pop_front();
	while(!q.empty()){
		int val=0;
		if(turn%2==1){
			while(!q.empty()&&val<=prev){
				val+=q.back();
				q.pop_back();
			}
			b += val;
		}
		else{
			while(!q.empty()&&val<=prev){
				val+=q.front();
				q.pop_front();
			}
			a+=val;
		}
		turn++;
		prev= val;
	}
	cout<<turn<<" "<<a<<" "<<b<<endl;

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		func();
	}
}