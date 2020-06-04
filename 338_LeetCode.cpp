class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num.size()+1);
        for(int i=0; i<=num ;i++){
        	v[i]=__builtin_popcount(i);
        }
        return v;
    }
};
//another way
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};