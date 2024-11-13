class Solution {
public:
    int minElement(vector<int>& nums) {
        int min=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int digit=nums[i];
            int sum=0;
            
            while(digit){
                sum += digit%10;
                digit /=10;
            }
            if(sum<min){
                min=sum;
            }
        }
        return min;
    }
};