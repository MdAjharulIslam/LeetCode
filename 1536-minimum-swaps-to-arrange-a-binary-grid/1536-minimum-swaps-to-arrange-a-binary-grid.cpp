class Solution {
public:
    int solver(vector<int>& arr) {
        int n = arr.size();
        int minSteps = 0;

        for(int i = 0; i < n; i++) {
            int need = n - i - 1;
            if(arr[i] >= need) continue;

            int j = i + 1;
            while(j < n && arr[j] < need) {
                j++;
            }

            if(j == n) return -1; // as, no row found for swap..
            minSteps += (j - i);

            // do the swaps
            while(j > i) {
                swap(arr[j], arr[j - 1]);
                j--;
            }
        }
        return minSteps;
    }

    int minSwaps(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int>rowWiseEndZeros(n, 0);

        for(int r = 0; r < n; r++) {
            int cnt = 0;
            int c = n - 1;
            while(c >= 0 && grid[r][c] == 0) {
                cnt++;
                c--;
            }
            rowWiseEndZeros[r] = cnt;
        }

        return solver(rowWiseEndZeros);
    }
};