class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int left=0;
        int right=nums.size()-1;
        int operations=0;
        
        sort(nums.begin(),nums.end());
        
        
        while(left<right){
            
            int sum=nums[left]+nums[right];
           
            if(sum==k){
                left++;
                right--;
                operations++;
            }else if(sum<k){
                left++;
            }else{
                right--;
            }
        }
        return operations;
    }
};