class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(Y <= X){ return (X-Y);}
        int ans=0;
        while(Y>X){
        	if(Y&1){
        		Y++;
        	}
        	else{
        		Y /=2;
        	}
        	ans++;
        }
        cout<<ans;
    }
};