#include<iostream>

using namespace std;

int CG(int n) {
    int freq[50]= {0};
    for(int i=1; i<=n; i++){
        int sum=0;
        int t = i;
        while(t>0){
            sum +=(t%10);
            t = t/10;
        }
        cout<<sum<<endl;
        freq[sum]++;
    }
    int maxfreq=0;
    for(int i=1; i<=n; i++){
        maxfreq = max(freq[i], maxfreq);
    } 
    return maxfreq;
}


int main(){
	cout<<CG(13);
}