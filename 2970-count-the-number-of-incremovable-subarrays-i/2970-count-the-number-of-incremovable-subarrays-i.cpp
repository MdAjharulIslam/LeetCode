class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        vector<int> start, end;
        
        for (int i = 0; i < n; ++i) {
            if (start.empty() || start.back() < nums[i]) {
                start.push_back(nums[i]);
            } else {
                break;
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            if (end.empty() || end.back() > nums[i]) {
                end.push_back(nums[i]);
            } else {
                break;
            }
        }
        
        if (start.size() + end.size() > n) {
            return 1LL * n * (n + 1) / 2;
        }
        
        long long ans = start.size() + end.size();
        int i = 0, j = 0;
        
        reverse(end.begin(), end.end());
        
        while (i < start.size() && j < end.size()) {
            if (start[i] < end[j]) {
                ans += end.size() - j;
                ++i;
            } else {
                ++j;
            }
        }
        
        return ans + 1;
    }
};
