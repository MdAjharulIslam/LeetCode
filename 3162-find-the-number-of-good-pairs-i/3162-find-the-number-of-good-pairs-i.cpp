class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans =0, div;
         for(auto val:nums1){
            for(auto v:nums2){
                div=v*k;
                if(val%div==0)
                ans++;
            }
         }return ans;
    }
};