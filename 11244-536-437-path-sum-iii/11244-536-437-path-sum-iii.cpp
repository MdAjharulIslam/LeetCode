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
    int pathSum(TreeNode* root, int targetSum) { 
       if (root == nullptr) return 0;
       return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + dfs(root, targetSum); 
    }

    int dfs(TreeNode* root, long long sum) {
        if (root == nullptr) return 0;
        int count = 0;
        if (root->val == sum) { ++count; }
        count += dfs(root->left, sum - root->val);
        count += dfs(root->right, sum - root->val);
        return count;
    }
};

