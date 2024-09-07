class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        
        int totalSum=0;
        int maxSum=INT_MIN;
        int minSum=INT_MAX;
        
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++){
            
            totalSum+=nums[i];
            sum1+=nums[i];
            sum2+=nums[i];
            
            
            maxSum = max(maxSum, sum1);
            minSum = min(minSum, sum2);

            if(sum1 < 0)
            sum1 = 0;

            if(sum2 > 0)
            sum2 = 0;
        }

        if(maxSum <= 0)
        return maxSum;

        return max(maxSum, totalSum - minSum);
        }
        
    
};