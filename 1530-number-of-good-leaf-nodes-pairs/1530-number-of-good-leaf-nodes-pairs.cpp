/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        helperFunction(root, distance, ans);
        return ans;
    }

    // Helper function for DFS traversal
    vector<int> helperFunction(TreeNode* root, int distance, int &ans) {
        if (root == nullptr) {
            return {};  // Return an empty vector for null nodes
        } else if (root->left == nullptr && root->right == nullptr) {
            return {1};  // Return distance 1 for leaf nodes
        }

        // Recursively get distances from left and right children
        auto L = helperFunction(root->left, distance, ans);
        auto R = helperFunction(root->right, distance, ans);

        // Count good pairs
        for (auto l : L) {
            for (auto r : R) {
                if (l + r <= distance) {
                    ans++;
                }
            }
        }

        // Update distances for the current node
        vector<int> ret;
        for (auto l : L) {
            if (l + 1 <= distance) {
                ret.push_back(l + 1);
            }
        }
        for (auto r : R) {
            if (r + 1 <= distance) {
                ret.push_back(r + 1);
            }
        }

        return ret;
    }
};