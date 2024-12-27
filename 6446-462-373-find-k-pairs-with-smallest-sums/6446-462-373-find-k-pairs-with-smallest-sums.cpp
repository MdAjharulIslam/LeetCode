class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) return result;

        auto compare = [&nums1, &nums2](pair<int, int>& a, pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);

        for (int i = 0; i < nums1.size() && i < k; ++i) {
            minHeap.emplace(i, 0);
        }

        while (!minHeap.empty() && pairs.size() < k) {
            auto [i, j] = minHeap.top();
            minHeap.pop();
            pairs.emplace_back(nums1[i], nums2[j]);

            if (j + 1 < nums2.size()) {
                minHeap.emplace(i, j + 1);
            }
        }

        for (const auto& p : pairs) {
            result.push_back({p.first, p.second});
        }

        return result;
    }
};