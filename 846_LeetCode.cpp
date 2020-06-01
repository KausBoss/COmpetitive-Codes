#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<ll, ll> m;
        for(auto x:hand){
        	m[x]++;
        }

        for(auto x=m.begin(); x!=m.end(); x++){
        	while(m[x->first]>0){
        		m[x->first]--;
        		for(int i=1; i<W; i++){
        			if(m.count(x->first + i)==0 || m[x->first + i]==0){
        				return false;
        			}
        			m[x->first + i]--;
        		}
        	}
        }
        return true;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    string line;
    while (getline(cin, line)) {
        vector<int> hand = stringToIntegerVector(line);
        getline(cin, line);
        int W = stringToInteger(line);
        
        bool ret = Solution().isNStraightHand(hand, W);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}