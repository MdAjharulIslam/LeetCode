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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postIndex = n - 1;
        return helper(inorder, postorder, postIndex, 0, n - 1);
    }

private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& postIndex, int left, int right) {
        if (left > right) return NULL;

        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        int pivot = left;
        while (inorder[pivot] != rootValue) pivot++;

        root->right = helper(inorder, postorder, postIndex, pivot + 1, right);
        root->left = helper(inorder, postorder, postIndex, left, pivot - 1);

        return root;
    }
};
