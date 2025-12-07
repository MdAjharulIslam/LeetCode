class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxr=0;
        for(int i=0;i<n;i++){
               if(maxr<i){
                return false;
               };
            
            maxr=max(maxr,nums[i]+i);
        }
    return true; 
        
        
        
    }
};