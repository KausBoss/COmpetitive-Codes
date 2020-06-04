class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k){return "0";}
        deque<int> s;
        int comp=k;
        for(int i=0; i<num.length(); i++){
        	int curr=num[i] - '0';
        	if(s.empty()){
        		s.push_back(curr);
        	}
        	else{
        		while(!s.empty() && s.back()>curr && k>0){
        			s.pop_back(); k--;
        		}
        		s.push_back(curr);
        	}
        }
        while(s.size()>(num.length()-comp)){
        	s.pop_back();
        }
        while(s.front()==0){s.pop_front();}
        string ans="";
        while(!s.empty()){
            ans += to_string(s.front());
            s.pop_front();
        }
        
        return ans==""? "0":ans;
    }
};