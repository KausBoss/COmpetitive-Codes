#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
 
using namespace std; 
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (998244353)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
#define int ll 
 
int a[123456],two[123456];
map<int,int> mapi; 
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int i;
	two[0]=1;
	f(i,1,123456){
		two[i]=two[i-1]*2;
		two[i]%=mod;
	}

	int t;
	cin>>t;
	while(t--){
		mapi.clear();
		int n;
		cin>>n;
		int i,maxi=0;
		rep(i,n){
			cin>>a[i];
			mapi[a[i]]++;
			maxi=max(maxi,a[i]);
		}
		mapi[maxi+1]=0;
	
		int previ=0,sofar=0;
		int befor=1,ways,tot=0;
		map<int,int>::iterator it;
		for(it=mapi.begin();it!=mapi.end();it++){
			if(it->ff==previ+1){
				ways=two[n-sofar-(it->ss)];
				ways*=befor;
				ways%=mod;
				ways*=(it->ff);
				ways%=mod;
				tot+=ways;
				tot%=mod;
				previ=it->ff;
			}
			else{
				ways=two[n-sofar];
				ways*=befor;
				ways%=mod;
				ways*=(previ+1);
				ways%=mod;
				tot+=ways;
				tot%=mod;
				break;
			}
			sofar+=it->ss;
			befor*=(two[it->ss]-1);
			befor%=mod;
		}
		cout<<tot<<endl;
	}
	
}