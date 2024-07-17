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
    vector<TreeNode*> forest;
    void dfs(TreeNode* root, set<int>& del)
    {
        if (root == NULL)
            return;
        
        dfs(root->left, del);
        dfs(root->right, del);

        if (root->left && del.find(root->left->val) != del.end())
        {
            root->left = NULL;
        }
        if (root->right && del.find(root->right->val) != del.end())
        {
            root->right = NULL;
        }

        if (del.find(root->val) != del.end())
        {
            if (root->left != NULL)
                forest.push_back(root->left);

            if (root->right != NULL)
                forest.push_back(root->right);
        }
        
        return ;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_del) {
        set<int> del(to_del.begin(), to_del.end());

        dfs(root, del);
        
        if (del.find(root->val) == del.end())
            forest.push_back(root);
            
        return forest;
    }
};