class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=1+i;j<nums.size();j++){
                if(nums[i]==nums[j]) return nums[i];
            }
        }
        return 0;
    }
};