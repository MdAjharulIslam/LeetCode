class Solution {
public:
    int mySqrt(int x) {
        int start=0, end=x;
        int ans;
        
        while(start<=end){
        long long mid=start+(end-start)/2;
            
            if(mid*mid==x){
            return mid;
            }
            if(mid*mid>x){
            
                end=mid-1;
            }else{
                
                start=mid+1;
                ans=mid;
            }
        }
        return ans;
    }
};