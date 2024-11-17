//using max heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxHeap;
        
        for(int i=0;i<nums.size();i++){
            maxHeap.push(nums[i]);
             }
        
            for(int i=0;i<k-1;i++){
                maxHeap.pop();
           
        }
        
        return maxHeap.top();
    }
};



//using min heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minq;
        
        // Iterate over the nums array
        for(int i = 0; i < nums.size(); i++) {
            // Add the current number to the heap
            minq.push(nums[i]);
            
            // If the heap size exceeds k, remove the smallest element
            while(minq.size() > k) {
                minq.pop();
            }
        }
        
        // The top of the heap is the k-th largest element
        return minq.top();
    }
};
