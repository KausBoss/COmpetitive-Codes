class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> p;
        if(a!=0){ p.push({a, 'a'});}
        if(b!=0){ p.push({b, 'b'});}
        if(c!=0){ p.push({c, 'c'});}

        string ans="";

        while(!p.empty()){
        	pair<int, char> t1 = p.top();
        	p.pop();
        	if(s.length()>=2 && s[s.length()-1]==t1.second && s[s.length()-2]==t1.second){
        		if(p.empty()){
        			return ans;
        		}
        		pair<int, char> t2 = p.top();
        		p.pop();
        		s.push_back(t2.second);
        		t2.first--;
        		if(t2.first != 0){
        			p.push(t2);
        		}
        	}
        	else{
        		s.push_back(t1.second);
        		t1.first--;
        	}
        	if(t1.first != 0){
        		p.push(t1);
        	}
        }
        return ans;
    }
};