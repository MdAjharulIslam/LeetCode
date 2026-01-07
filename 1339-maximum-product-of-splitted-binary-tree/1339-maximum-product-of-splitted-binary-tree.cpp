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

    int mod = 1e9+7;
    vector<int> sums;
    

    int post(TreeNode* root){
        
        if(root == NULL) return 0 ;

        int l = post(root->left);
        int r = post(root->right);

        int sum = root->val+l+r;
        sums.push_back(sum);
        return sums.back();
    }

    int maxProduct(TreeNode* root) {
        

        long long rootsum = post(root), ans=0;

        for(int i=0; i<sums.size(); i++)
            ans = max(ans , sums[i] * (rootsum-sums[i]));

        return ans%mod;

    }
};