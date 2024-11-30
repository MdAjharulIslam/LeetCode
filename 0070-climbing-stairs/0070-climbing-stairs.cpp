class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        
        int prev1=1 ,prev2=1,current;
        
        for(int i=1;i<n;i++){
            current =prev1+prev2;
            prev2=prev1;
            prev1=current;
        }
        return current;
    }
};