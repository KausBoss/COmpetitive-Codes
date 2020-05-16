#define ll long long
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> reservedSeats) {
        ll total = 2*n;
        map<ll, vector<int>> m;
        for(auto x: reservedSeats){
        	m[x[0]].push_back(x[1]);
        }
        ll not_poss=0;
        for(auto x:m){
        	bitset <11> st;
        	for(auto y:x.second){
        		st[y]=1;
        	}
        	bool f1= (st[2] | st[3] | st[4] | st[5]);
        	bool f2= (st[6] | st[7] | st[8] | st[9]);
        	bool f3= (st[4] | st[5] | st[6] | st[7]);

        	if(f1 && f2 && f3){
        		not_poss+=2;
        	}
        	else if((f1 || f2) && !f3){
        		not_poss++;
        	}
        	else if((f1 && !f2) || (!f1 && f2)){
        		not_poss++;
        	}
        }
        return total- not_poss;
    }
};