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
  bool is_balanced = true;
  int dfs(TreeNode* node) {
    if (!is_balanced || !node) return 0;
    int l = dfs(node->left), r = dfs(node->right);
    if (abs(l - r) > 1) is_balanced = false;
    return 1 + max(l, r);
  }

 public:
  bool isBalanced(TreeNode* root) {
    dfs(root);
    return is_balanced;
  }
};