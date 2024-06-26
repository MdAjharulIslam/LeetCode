class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int count=1;
    
        for(int i=1;i<n;i++){
            if(count==1||nums[i]!=nums[count-2]){
                nums[count]=nums[i];
                count++;
        }
    }
        return count;
    }
};