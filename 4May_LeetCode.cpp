class Solution {
public:
    int findComplement(int num) {
        int mask=1;
        int i=0;
        int temp=num;
        while(temp > 0){
            mask = mask | 1<<i;
            i++;
            temp=temp>>1;
        }
        return (mask^num);
    }
};