#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    // Segment Tree Node
    struct Node {
        int min_val;
        int max_val;
        int lazy;
    };

    vector<Node> tree;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {0, 0, 0};
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = {0, 0, 0};
        }
    }

    void push(int node) {
        if (tree[node].lazy != 0) {
            tree[2 * node].min_val += tree[node].lazy;
            tree[2 * node].max_val += tree[node].lazy;
            tree[2 * node].lazy += tree[node].lazy;

            tree[2 * node + 1].min_val += tree[node].lazy;
            tree[2 * node + 1].max_val += tree[node].lazy;
            tree[2 * node + 1].lazy += tree[node].lazy;

            tree[node].lazy = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (l > end || r < start) return;
        if (l <= start && end <= r) {
            tree[node].min_val += val;
            tree[node].max_val += val;
            tree[node].lazy += val;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node].min_val = min(tree[2 * node].min_val, tree[2 * node + 1].min_val);
        tree[node].max_val = max(tree[2 * node].max_val, tree[2 * node + 1].max_val);
    }

    // Find the smallest index in range [0, limit] that has value 0
    int queryFirstZero(int node, int start, int end, int limit) {
        // If the range [start, end] is completely out of bounds
        if (start > limit) return -1;

        // Optimization: If 0 is not within the range of values [min, max] covered by this node, 
        // it's impossible to find a zero here.
        if (tree[node].min_val > 0 || tree[node].max_val < 0) return -1;

        if (start == end) {
            return (tree[node].min_val == 0) ? start : -1;
        }

        push(node);
        int mid = (start + end) / 2;
        
        // Try to find in the left child first (to find the smallest index)
        int res = queryFirstZero(2 * node, start, mid, limit);
        if (res != -1) return res;
        
        // If not found in left, try right
        return queryFirstZero(2 * node + 1, mid + 1, end, limit);
    }

public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        // Tree covers indices 0 to n-1.
        tree.resize(4 * n);
        build(1, 0, n - 1);

        map<int, int> last_pos;
        int max_len = 0;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            int type = (val % 2 == 0) ? 1 : -1; // Even = +1, Odd = -1
            
            int prev = -1;
            if (last_pos.count(val)) {
                prev = last_pos[val];
            }
            
            // Update range [prev + 1, i]
            // This range represents all starting positions L where nums[i] is a NEW distinct element.
            update(1, 0, n - 1, prev + 1, i, type);
            
            last_pos[val] = i;

            // Find smallest L in [0, i] such that balance is 0
            int l_idx = queryFirstZero(1, 0, n - 1, i);
            
            if (l_idx != -1) {
                max_len = max(max_len, i - l_idx + 1);
            }
        }

        return max_len;
    }
};