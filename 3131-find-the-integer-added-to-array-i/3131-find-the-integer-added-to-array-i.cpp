class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int n=nums1.size();
        int totalDiff=0;
        for(int i=0;i<n;i++){
            totalDiff+=nums2[i]-nums1[i];
            
        }
        return totalDiff/n;
    }
};