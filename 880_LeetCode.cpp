#include <bits/stdc++.h>

using namespace std;

#define ll long long	

string decodeAtIndex(string S, int k) {
 	stack<pair<string, int> > s;
 	string str;
 	for(int i=0; i<S.length(); i++){
 		if(isalpha(S[i])){
 			str += S[i];
 		}
 		else{
 			int dig=S[i] - '0';
 			int sec=!s.empty()?(s.top().second + str.length())*dig : (str.length())*dig;
 			//cout<<str<<" "<<sec<<endl;
 			if(str.empty()){s.top().second *= dig;}
 			else{s.push(make_pair(str, sec));}
 			str.clear();
 			if(s.top().second >= k){break;}
 			//cout<<s.top().first<<"  "<<s.top().second<<endl;
 		}
 	}
 	while(!s.empty()){
		auto p = s.top();
		string x = p.first;
		int l = p.second;
		s.pop();

		k = k%(x.length() +(s.empty()?0:s.top().second));
		if(k == 0) k = x.length() +(s.empty()?0:s.top().second);
		if(s.empty()){
			string ans = "";
			ans += x[k-1];
			return ans;
		}
		if(k>s.top().second){
			string ans = "";
			ans += x[k-s.top().second-1];
			return ans;
		}
	}
	string r = "";
	r +=S[k-1];
	return r;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cout<<decodeAtIndex("abc", 2);
}