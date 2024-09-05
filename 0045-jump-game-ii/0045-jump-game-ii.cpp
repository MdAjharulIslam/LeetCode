class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size()-1;
        int maxReach=0;
        int count=0;
        int last=0;
        for(int i=0;i<n;i++){


            maxReach=max(maxReach,i+nums[i]);
            
            if(i==last){
                last=maxReach;
            count++;
            }
        }
        return count;
    }
};