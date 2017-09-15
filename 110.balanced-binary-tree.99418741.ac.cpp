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
    bool isBalanced(TreeNode* root) {
        pair<bool, int> res = helper(root);
        return res.first;
    }
    
    pair<bool, int> helper(TreeNode* root) {
        if(!root) {
            return make_pair(true, 0);
        }
        pair<bool, int> left = helper(root->left);
        pair<bool, int> right = helper(root->right);
        return make_pair(left.first && right.first && abs(left.second - right.second) <= 1, max(left.second, right.second) + 1);
    }
};