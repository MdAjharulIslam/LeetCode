class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> p;
        
        // Create pairs (nums2[i], nums1[i])
        for (int i = 0; i < nums1.size(); i++) {
            p.push_back({nums2[i], nums1[i]});
        }
        
        // Sort the pairs in descending order based on nums2 values
        sort(p.rbegin(), p.rend());
        
        long long ans = 0;
        long long sum = 0;
        priority_queue<int> pq;
        
        // Preprocess first k-1 elements
        for (int i = 0; i < k - 1; i++) {
            sum += p[i].second;
            pq.push(-p[i].second); // Store negative values to use as a min-heap
        }
        
        // Iterate from the k-1 element onwards
        for (int i = k - 1; i < nums1.size(); i++) {
            sum += p[i].second;
            pq.push(-p[i].second);
            
            // Calculate the maximum score
            ans = max(ans, sum * p[i].first);
            
            // Remove the smallest element from sum
            sum += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};
