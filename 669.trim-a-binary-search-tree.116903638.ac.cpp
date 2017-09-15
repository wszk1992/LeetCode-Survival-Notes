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
    //   5
    //  3  8
    //1   6  11
    // [2,8]
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) {
            return NULL;
        }
        if(root->val < L) {
            return trimBST(root->right, L, R);
        } else if(root->val > R) {
            return trimBST(root->left, L, R);
        } else {
            TreeNode* cur = new TreeNode(root->val);
            cur->left = trimBST(root->left, L, root->val);
            cur->right = trimBST(root->right, root->val, R);
            return cur;
        }
    }
};