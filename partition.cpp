#include <bits/stdc++.h>
#include <vector>

#define F(a,n) for(int i=0; i<n; i++){cout<<a[i]<<" ";}

using namespace std;

int pj(vector<int>& A) {
    int temp;
    int n = A.size();
    vector<int> lmax, rmin;
    lmax.push_back(A[0]);
    temp = A[0];
    for(int i=1; i<n; i++){
        temp = max(temp, A[i]);
        lmax.push_back(temp);
    }
    temp = A[n-1];
    rmin.push_back(temp);
    for(int i=n-2; i>=0; i--){
        temp = min(temp, A[i]);
        rmin.push_back(temp);
    }
    reverse(rmin.begin(), rmin.end());
    int ans = 1;
    for(int i=0; i<n-1; i++){
        if(lmax[i] > rmin[i+1]){
            ans++;
        }
        else{
            break;
        }
    }
    return ans;
}



int main(){
	vector<int> v{5,0,3,8,6};
	cout<<pj(v);
}