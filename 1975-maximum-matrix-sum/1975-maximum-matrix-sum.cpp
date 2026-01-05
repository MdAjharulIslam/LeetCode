class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum =0;
        int negcnt = 0;
        int mini = INT_MAX;
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]<0){
                    matrix[i][j] = -matrix[i][j];
                    negcnt++;
                    
                }
                mini = min(mini, matrix[i][j]);
                sum = sum + matrix[i][j];
            }
        }
        if(negcnt%2){
            sum-=2*mini;
        }
        return sum;
    }
};