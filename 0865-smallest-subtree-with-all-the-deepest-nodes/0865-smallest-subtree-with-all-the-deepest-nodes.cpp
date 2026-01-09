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
    int max_level = 0; 
    void deepest_level(TreeNode* root,int curr_level)
    {
        if(!root) return; 

        max_level = max(curr_level,max_level);

        deepest_level(root->left,curr_level+1);
        deepest_level(root->right,curr_level+1);

    }

    TreeNode* deepest_lca(TreeNode* root , int &max_level , int curr_level)
    {
        if(!root || curr_level==max_level)
        {
            return root;
        }

        TreeNode* left = deepest_lca(root->left,max_level,curr_level+1);
        TreeNode* right = deepest_lca(root->right,max_level,curr_level+1);

        if(left==NULL) return right;
        if(right==NULL) return left;

        return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        deepest_level(root,0);

        return deepest_lca(root,max_level,0); 
    }
};