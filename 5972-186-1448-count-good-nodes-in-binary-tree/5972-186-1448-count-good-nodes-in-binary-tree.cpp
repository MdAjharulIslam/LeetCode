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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        int numGoodNodes=0;
        stack<pair<TreeNode*, int >> st;
        st.push({root,INT_MIN});

        while(!st.empty()){
            auto [node,maxVal]=st.top();
            st.pop();
            if(node->val >= maxVal){
                numGoodNodes += 1;
                maxVal=node->val;
            }

            if(node->right) st.push({node->right, maxVal});
            if(node->left) st.push({node->left,maxVal});
                    }
                    return numGoodNodes;
    }
};