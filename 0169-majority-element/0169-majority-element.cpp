class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int elements;
        for(int i=0;i<n;i++){
            if(count==0){
                count++;
                elements=nums[i];
                
            }
            else if(elements==nums[i]){
                count++;
            }
            else{
            count--;
            }
            
        }
        return elements;
    }
};