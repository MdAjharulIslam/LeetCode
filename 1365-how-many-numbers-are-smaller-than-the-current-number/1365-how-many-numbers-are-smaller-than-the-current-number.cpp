class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();

       vector<int>x(n);
        for(int i=0;i<n;i++){
            int  count=0;
            for(int j=0;j<n;j++){
                if(nums[j]<nums[i] &&j!=i){
                    count++;
                }
            }
             x[i] = count;
        }
        return x;
    }
};