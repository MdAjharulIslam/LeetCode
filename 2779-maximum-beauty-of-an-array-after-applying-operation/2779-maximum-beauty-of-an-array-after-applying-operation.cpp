class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
         sort(nums.begin(),nums.end());
        int start = 0, ans = 0;
        for(int i=0; i<nums.size(); i++){     
            
            while(nums[i]-nums[start] > 2*k)
                start++;
            
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};