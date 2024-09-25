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
    
    TreeNode*prev=nullptr;
    
    void inorder(TreeNode*root,int &ans){
        
        if(!root){
            return;
        }
        
        inorder(root->left,ans);
        
        if(prev!=nullptr){
            int diff=abs(prev->val-root->val);
            ans=min(ans,diff);
        }
        
        prev=root;
        inorder(root->right,ans);
            
        
    }
    
    
    int getMinimumDifference(TreeNode* root) {
         int ans=INT_MAX;
        inorder(root,ans);
        return ans;
    }
};