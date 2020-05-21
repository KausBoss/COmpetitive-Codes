class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int dif = n-m;
        if(dif == 0)return m;
        int pos = ceil(log2(dif));
        //cout<<pos<<endl;
        for(int i=0; i<pos; i++){
        	int mask = 1<<i;
        	mask = ~mask;
        	m = (m&mask);
        }
        return m&n;
    }
};