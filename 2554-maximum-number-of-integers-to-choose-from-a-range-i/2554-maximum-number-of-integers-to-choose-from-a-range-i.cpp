class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
    int res = 0;
    unordered_set<int> s(begin(banned), end(banned));
    for (int x = 1; x <= n && maxSum >= 0; ++x) 
        if (s.count(x) == 0) {
            maxSum -= x;
            res += maxSum >= 0;
        }
    return res;
      }
};