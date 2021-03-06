/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return exchangeTree(root);
    }
    TreeNode* exchangeTree(TreeNode* root)
    {
        if(root==NULL)
            return NULL;
        TreeNode* temp;
        temp = exchangeTree(root->left);
        root->left = exchangeTree(root->right);
        root->right = temp;
        return root;
    }
};