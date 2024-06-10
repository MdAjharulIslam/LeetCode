class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (__builtin_popcount(i) == k) {
                sum += nums[i];
            }
        }
        
        return sum;
    }
};
