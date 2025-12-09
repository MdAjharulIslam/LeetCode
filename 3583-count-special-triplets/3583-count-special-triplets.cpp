#define MOD 1000000007
#define MX (1e5 / 2)
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int v[100001]={0};
        int v1[100001]={0};
    
        int ans = 0;
        for (int i = 0; i<n; i++) 
        {
            if((nums[i]&1) == 0)
            {
                ans= ((long long)ans + v1[nums[i]/2])%MOD;
            }
            v1[nums[i]] = (v1[nums[i]] + v[nums[i]])%MOD;
            if ((nums[i]&1)==0) v[nums[i]/2]+=1;
        }
        return ans;
    }
};