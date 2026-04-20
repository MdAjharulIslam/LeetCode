class Solution {
public:
    int maxDistance(vector<int>& A) {
        int j = A.size();

        for (int i = 0; i < j; i++)
            if ((A[i] ^ A.back()) | (A[j - 1 - i] ^ A[0]))
                return j - 1 - i;

        return 0;
    }
};