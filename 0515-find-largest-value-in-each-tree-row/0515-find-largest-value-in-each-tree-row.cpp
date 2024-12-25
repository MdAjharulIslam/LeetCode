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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int>ans;
        queue<TreeNode *>q;
        
       if(root) q.push(root);
        
        while(!q.empty()){
            int len=q.size() , maxVal=INT_MIN;
            
            while(len--){
                auto temp=q.front();
                
                q.pop();
                maxVal=max(maxVal,temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                
            }
            
            ans.push_back(maxVal);
        }
        return ans;
    }
};