class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int n=nums.size();
        int i=0, j=0;
        while(j<n){
            if(nums[j]!=val){
                int temp = nums[i];
                nums[i++]=nums[j];
                nums[j++]=temp;
            }
            else{
                j++;
            }
        }
          return i;
    }
};