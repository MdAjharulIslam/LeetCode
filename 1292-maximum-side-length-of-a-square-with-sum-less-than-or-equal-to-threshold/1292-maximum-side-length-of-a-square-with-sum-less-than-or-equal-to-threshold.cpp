class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        // Prefix sum
        vector<vector<int>> row(m, vector<int>(n + 1, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + mat[i][j];
            }
        }

        for(int side = min(m, n); side >= 1; side--) {
            for(int r = 0; r + side <= m; r++) {
                for(int c = 0; c + side <= n; c++) {

                    long long allRowsSum = 0;
                    for(int i = r; i < r + side; i++) {
                        allRowsSum += (row[i][c + side] - row[i][c]);
                        if(allRowsSum > threshold) break;
                    }

                    if(allRowsSum <= threshold)
                        return side;
                }
            }
        }

        return 0;
    }
};