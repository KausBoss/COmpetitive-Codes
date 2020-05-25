#include <bits/stdc++.h>

using namespace std;
#define ll long long 
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


int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("input.txt",  "r",   stdin);
      freopen("output.txt", "w",  stdout);
      #endif
      fastIO
      ll x;
      cin >> x;
      ll cnt = 0;
      vector <ll> v;
      while (true){
            ll temp = x;
            ll f = 1;
            ll c = 0;
            while (temp){
                  ll r = temp%2;
                  if (r == 0){
                        f = 0;
                  }
                  temp/=2;
                  c+= 1;
            }
            if (f == 1){
                  break;
            }
            ll p = (ll)pow(2,c)-1;
            x = x xor p;
            cnt+=1;
            v.push_back(c);
            temp = x;
            f = 1;
            while (temp){
                  ll r = temp%2;
                  if (r == 0){
                        f = 0;
                        break;
                  }
                  temp/=2;
                  c+= 1;
            }
            if (f == 1){
                  break;
            }
            x += 1;
            cnt+=1;
      }
      cout << cnt << "\n";
      for(ll i = 0; i < v.size(); i += 1){
            cout << v[i] << " ";
      }
      return 0;
}