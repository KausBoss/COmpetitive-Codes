// The API isBadVersion is defined for you.
// bool isBadVersion(long  version);

class Solution {
public:
    int  firstBadVersion(int  n) {
        int  s=1;
        int  e=n;
        while(s<e){
        	long long mid=((long)s+(long)e)/2;

        	if(isBadVersion((int)mid)){
        		e=(int)mid;
        	}
        	else{
        		s=(int)mid+1;
        	}
        }
        return s;
    }
};