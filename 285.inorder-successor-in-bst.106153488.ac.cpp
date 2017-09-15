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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool found = 0;
        TreeNode* successor = NULL;
        findSuccessor(root, p, found, successor);
        return successor;
    }
    
    void findSuccessor(TreeNode* root, TreeNode*& p, bool& found, TreeNode*& successor) {
        if(successor) {
            return;
        } 
        if(!root) {
            return;
        }
        findSuccessor(root->left, p, found, successor);
        if(found && !successor) {
            successor = root;
            return;
        }
        if(p == root) {
            found = true;
        }
        findSuccessor(root->right, p, found, successor);
    }
};