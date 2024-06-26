class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),left=1,right=1;
        
        vector<int>answer(n,1);
        
        for(int i=0;i<n;i++){
            answer[i]=left;
            left *=nums[i];
        }
        
        for(int i=n-1;i>=0;i--){
            answer[i] *= right;
            right *=nums[i];
        }
        return answer;
    }
};