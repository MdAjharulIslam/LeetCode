class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        const int NEG_INF = -1e9;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG_INF));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int product = nums1[i - 1] * nums2[j - 1];
                
                dp[i][j] = max({
                    product,
                    product + dp[i - 1][j - 1],
                    dp[i - 1][j],
                    dp[i][j - 1]
                });
            }
        }
        
        return dp[n][m];
    }
};