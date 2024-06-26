class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m,j=0;j<n;j++){
            
            nums1[i]=nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }
};