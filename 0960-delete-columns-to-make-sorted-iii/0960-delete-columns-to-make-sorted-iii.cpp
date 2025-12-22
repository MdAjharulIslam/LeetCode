class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int col = strs[0].size();
        int LIS = 1;
        vector<int> dp(col, 1);

        for(int i=0 ; i<col ; i++){
            for(int j=0 ; j<i ; j++){

                bool safe = true;

                for(int k=0 ; k<rows ; k++){
                    if(strs[k][j] > strs[k][i]){
                        safe = false;
                        break;
                    }
                }
                if(safe){
                    dp[i] = max(dp[i] ,dp[j] + 1);
                }
            LIS = max(LIS, dp[i]);
            }
        }
        return col - LIS;
    }
};