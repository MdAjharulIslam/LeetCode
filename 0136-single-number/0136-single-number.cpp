class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int a=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            a=a^nums[i];
        }
        return a; 
    }
};