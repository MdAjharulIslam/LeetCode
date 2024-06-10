class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans(2, -1);

        
        int s = 0, n = nums.size() - 1;
        int mid;
        while (s <= n) {
            mid = s + (n - s) / 2;
            if (nums[mid] == target) {
                ans[0] = mid;
                n = mid - 1;  
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                n = mid - 1;
            }
        }
      s = 0, n = nums.size() - 1;
        while (s <= n) {
            mid = s + (n - s) / 2;
            if (nums[mid] == target) {
                ans[1] = mid;
                s = mid + 1;  
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                n = mid - 1;
            }
        }
        return ans;
    }
};