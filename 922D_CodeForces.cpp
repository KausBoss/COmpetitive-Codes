#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

ll CountNoise(string s){
	ll n=s.length();
	ll Hcount=0, noise=0;
	for(ll i=0; i<n; i++){
		if(s[i]=='h'){Hcount++;}
	}

	for(ll i=0; i<n; i++){
		if(s[i]=='s'){
			noise += Hcount;
		}
		else{
			Hcount--;
		}
	}
	return noise;
}

bool comp(string a, string b){
	string AthenB = a+b;
	string BthenA = b+a;
	ll noiseAB = CountNoise(AthenB);
	ll noiseBA = CountNoise(BthenA);

	return noiseAB>noiseBA;
}

int main(){
	ll n;
	string s, final;
	vector<string> v;
	cin>>n;
	for(ll i=0;i<n; i++){
		cin>>s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), comp);

	for(ll i=0; i<v.size(); i++){
		final += v[i];
	}

	cout<<CountNoise(final);
}