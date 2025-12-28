class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rightLimit = grid[0].size();
        int sum = 0;
        for(int i = 0;i < grid.size();i++) {
            for(int j= 0;j < rightLimit;j++) {
                if(grid[i][j] < 0) {
                    sum  += ((grid.size() - i) * (rightLimit - j));
                    rightLimit = j;
                }
            }
        }
        return sum;
    }
};