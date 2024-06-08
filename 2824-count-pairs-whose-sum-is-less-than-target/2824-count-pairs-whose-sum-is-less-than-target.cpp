class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(nums[i]+nums[j]<target &&i<j)
                ans++;
        }
        }
        return ans;
    }
};