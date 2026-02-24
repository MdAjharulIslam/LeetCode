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
    void f(TreeNode* node, vector<int> &ans, int num){
        if(node->val == 0){
            if(num == 0) num = 0;
            else{
                num = num << 1;
            }
        }
        if(node->val == 1){
            if(num == 0) num = 1;
            else{
                num = num << 1;
                num = num + 1;
            }
        }
        if(node->left){
            f(node->left,ans,num);
        }
        if(node->right){
            f(node->right,ans,num);
        }
        if(!node->left && !node->right){
            ans.push_back(num);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> ans;
        int num = 0;
        f(root,ans,num);
        int sum = 0;
        for(int i = 0 ; i < ans.size() ; i++){
            sum += ans[i];
        }
        return sum;
    }
};