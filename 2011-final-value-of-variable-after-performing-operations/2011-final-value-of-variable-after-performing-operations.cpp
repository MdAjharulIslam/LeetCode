class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
            int x = 0;
        int n=operations.size();
        for (int i=0;i<n;i++) {
            if (operations[i][1]=='+') {
                x++;
            } else {
                x--;
            }
        }
        return x;
    
    }
};