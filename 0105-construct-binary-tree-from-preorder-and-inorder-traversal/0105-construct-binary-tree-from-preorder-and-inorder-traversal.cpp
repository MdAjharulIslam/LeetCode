class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int index = 0;
        return helper(preorder, inorder, index, 0, n - 1);
    }


    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &index, int left, int right) {
        if (left > right) {
            return NULL;
        }

        int pivot = left;
        while (inorder[pivot] != preorder[index]) pivot++;

        index++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = helper(preorder, inorder, index, left, pivot - 1);
        newNode->right = helper(preorder, inorder, index, pivot + 1, right);
        return newNode;
    }
};
