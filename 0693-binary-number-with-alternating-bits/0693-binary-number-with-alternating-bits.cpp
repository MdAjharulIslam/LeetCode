class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^ (n >> 1)) & ((long long)(n ^ (n >> 1)) + 1));
    }
};