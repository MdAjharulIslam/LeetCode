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
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    TreeNode* tree(vector<int>& ans, int s, int e) {
        if (s > e) {
            return NULL;
        }
        int mid = (s + e) / 2;
        TreeNode* element = new TreeNode(ans[mid]);
        element->left = tree(ans, s, mid - 1);
        element->right = tree(ans, mid + 1, e);
        return element;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        int s = 0;
        int e = ans.size() - 1;
        return tree(ans, s, e);
    }
};