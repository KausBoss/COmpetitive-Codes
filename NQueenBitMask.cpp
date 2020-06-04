#include <bits/stdc++.h>

using namespace std;

#define ll long long
int ans=0;
#define DONE (1<<n)-1

void NQueen(int col,int ld,int rd,int n){
	// Base Case
	if(col == DONE){
		ans++;
		return;
	}

	// Recursive case
	int RemainingColumns = DONE&(~(col|ld|rd));
	while(RemainingColumns>0){
		int pos = RemainingColumns&(-RemainingColumns);
		RemainingColumns -= pos;
		NQueen(col|pos,(ld|pos)<<1,(rd|pos)>>1,n);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	NQueen(0,0,0,n);
	cout<<ans<<endl;
	
}