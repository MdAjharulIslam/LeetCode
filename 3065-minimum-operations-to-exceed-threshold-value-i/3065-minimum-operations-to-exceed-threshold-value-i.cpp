class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]>=k)
                break;
            count++;
            
        }
        return count;
    }
};