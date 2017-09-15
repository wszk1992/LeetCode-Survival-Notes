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
    bool isSymmetric(TreeNode* root) {
        return !root || symTree(root->left, root->right);
    }
    
    bool symTree(TreeNode* t1, TreeNode* t2) {
        if(t1 && !t2 || !t1 && t2) {
            return false;
        }
        if(!t1 && !t2) {
            return true;
        }
        return t1->val == t2->val && symTree(t1->left, t2->right) && symTree(t1->right, t2->left);
    }
};