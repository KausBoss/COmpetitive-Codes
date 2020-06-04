class Solution {
public:
	map<pair<int,int>, int> m;
	int func(int l, int r, string s){
		//base case
		if(l > r){return 0;}
		if(r==l){return 1;}

		//recursive case
		if(m.count(make_pair(l,r))){return m[make_pair(l, r)];}

		int ans = 1+ func(l+1, r, s);

		for(int i=l+1; i<=r; i++){
			if(s[i]==s[l]){
				ans = min(ans, func(l+1, i, s) + func(i+1, r, s));
			}
		}
		m[make_pair(l,r)]=ans;
		return ans;
	}
    int strangePrinter(string s) {
        return func(0, s.length()-1, s);
    }
};