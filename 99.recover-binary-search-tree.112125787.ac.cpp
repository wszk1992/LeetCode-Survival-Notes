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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> mistakes;
        TreeNode* last = new TreeNode(INT_MIN);
        inorder(root, last, mistakes);
        int temp = mistakes[0]->val;
        mistakes[0]->val = mistakes[1]->val;
        mistakes[1]->val = temp;
    }
    
    void inorder(TreeNode* root, TreeNode*& last, vector<TreeNode*>& mistakes) {
        if(!root) {
            return;
        }
        inorder(root->left, last, mistakes);
        if(root->val < last->val) {
            if(mistakes.empty()) {
                //last is mistake 1;
                //let root be the candidate of mistake 2;
                mistakes.push_back(last);
                mistakes.push_back(root);
            } else {
                //root is mistake 2;
                mistakes[1] = root;
            }
        }
        last = root;
        inorder(root->right, last, mistakes);
    }
};