#include <bits/stdc++.h>

using namespace std;

#define ll long long

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
        ll n;
        cin>>n;
        ll a = 2*(pow(2,n-1)-1);
        ll c = 2*(pow(2,(n-2)/2)-1);
        a -=c;
        ll b = pow(2, n);
        b += c;
        cout<<abs(b-a)<<endl;
    }
}