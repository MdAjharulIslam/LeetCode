class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> h(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    h[i][j] = (i > 0 ? h[i - 1][j] : 0) + 1;
                }
            }
            for (int j = 0; j < m; j++) {
                int mn = h[i][j];
                for (int k = j; k < m && mn > 0; k++) {
                    mn = min(mn, h[i][k]);
                    ans = max(ans, mn * (k - j + 1));
                }
            }
        }
        return ans;
    }
};